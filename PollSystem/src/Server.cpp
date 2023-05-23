#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <map>
#include <thread>
#include <mutex>
std::mutex poll_mutex;


void addPollOptions();
int processPollOptions();
int getNumberOfClients();
void communicateWithClient(int);
void printResult(int, int);
void acceptConnection(int);
void sendMessage(int, std::string);
void receiveMessage(int);
void addPollCount(std::string);
int checkDuplicateEntry(std::string);
std::string prepareMessageToSend();
void printPollChoice();

std::vector<std::string> poll_options;
std::vector<int> poll_results;
int number_of_clients, clients_participated = 0;

int main() {
  
  int server_socket, client_socket, port_number;
  struct sockaddr_in server_address;

  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket < 0) {
    std::cerr << "Error opening socket.\n";
    exit(1);
  }

  std::memset(&server_address, 0, sizeof(server_address));
  port_number = 8080;
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(port_number);

  if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
      std::cerr << "Error on binding.\n";
      exit(1);
  }
  
  //add polling choices
  addPollOptions();

  number_of_clients = getNumberOfClients();

  //listen and accept client connections
  acceptConnection(server_socket);

  printResult(number_of_clients, clients_participated);
  close(server_socket);
}

int getNumberOfClients() {

    int clients_count = 0;
    std::cout << "Enter number of clients to participate.." << std::endl; 
    std::cin >> clients_count;

    if(clients_count > 0) {
        return clients_count;
    }
    else {
        std::cout << "Enter a Valid Input" << std::endl;
        return getNumberOfClients();
    }
}

void acceptConnection(int server_socket) {

    int client_socket;
    struct sockaddr_in client_address;
    socklen_t client_length;

    if((listen(server_socket, 5)) == -1) {
      std::cerr << "Error in listening.\n";
    }
    while(true) {
        client_length = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_length);

        //count the participants to check how many clients can participate
        clients_participated++;
        if(clients_participated > number_of_clients) {
            sendMessage(client_socket, "Poll has ended.");
            clients_participated--;
            close(client_socket);
            break;
        }

        std::thread clientThread(communicateWithClient, client_socket);
        if(clientThread.joinable()) {
            clientThread.detach();
        }
    }
}

void addPollOptions() {

    int loop_control = 1, optionsCount = 1;
    std::cout << "Enter the choices for poll" << std::endl;
    std::string option_entry;

    while(loop_control) {
        int user_choice = 0;
        option_entry = "";
        std::cout << "Option " << optionsCount++ << std::endl;
        std::getline(std::cin >> std::ws, option_entry);

        int isDuplicate = checkDuplicateEntry(option_entry);
        if(isDuplicate == 1) {
            poll_options.push_back(option_entry);
        } else {
            optionsCount--;
            std::cout << "This choice is already available in list." << std::endl;
        }

        std::cout << "Enter 1 to add Choice" << std::endl;
        std::cout << "Enter 0 to continue" << std::endl;
        std::cin >> user_choice;
        loop_control = user_choice;

        if(loop_control != 1) {
            printPollChoice();
            user_choice = processPollOptions();

            if(user_choice == 1) {
                loop_control = 0;
            } else if(user_choice == 2) {
                loop_control = 1;
            } else if(user_choice == 0) {
                std::cout << "Program Terminated" << std::endl;
                exit(1);
            } else {
                loop_control = 1;
            }
        }
    }
}

int checkDuplicateEntry(std::string newEntry) {

    for(int i=0; i<poll_options.size(); i++) {
        if(poll_options[i] == newEntry) {
            return 0;
        }
    }
    return 1;
}

int processPollOptions() {
    int loopControl;
    std::cout << std::endl;
    std::cout << "Do you want to continue :\n";
    std::cout << "Enter 1 for continue with options\n";
    std::cout << "Enter 2 for adding options\n";
    std::cout << "Enter 0 for exit the process\n";
    std::cin >> loopControl;
    return loopControl;
}

void communicateWithClient(int client_socket) {

    if (client_socket < 0) {
      std::cerr << "Error on accept.\n";
      exit(1);
    }
    std::string message = prepareMessageToSend();
    sendMessage(client_socket, message);
    receiveMessage(client_socket);
    close(client_socket);
}

std::string prepareMessageToSend() {

    std::string message_to_send = "Poll your choice: ";
    for(int i=0; i<poll_options.size(); i++) {
        message_to_send.append("\n" + poll_options[i] + " ");
    }

    return message_to_send;
}

void sendMessage(int client_socket, std::string message_to_send) {
   
    int bytes_read = send(client_socket, message_to_send.c_str(), message_to_send.size(), 0);
    if (bytes_read < 0) {
        std::cerr << "Error in sending message to client socket.\n";
    }
}

void receiveMessage(int client_socket) {

    int bytes_read;
    std::string incoming_message;
    bytes_read = read(client_socket, &incoming_message, 255);
    if (bytes_read < 0) {
        std::cerr << "Error reading from socket.\n";
        close(client_socket);
    }
    else {
        std::cout << "Client choice : " << incoming_message << std::endl;
        addPollCount(incoming_message);
    }
}

void addPollCount(std::string incoming_message) {

    int index = std::stoi(incoming_message);
     //if the list has value, else add new value to the index;
    if(poll_results.size() >= index) {
        index--;
        poll_results[index]++;
    }
    else {
        poll_results.resize(index);
        index--;
        poll_results[index] = 1;
    }
}

void printResult(int clients, int participants) {

    std::cout << "\nPoll Result: " << std::endl;
    std::cout << "Total number of participants: " << clients << std::endl;
    std::cout << "Participated clients: " << participants << std::endl;
    
    for(int i=0; i<poll_options.size(); i++) {
        std::cout << poll_options[i] << " - " << poll_results[i] << std::endl; 
    }
}

void printPollChoice() {

    std::cout << "\nPoll Choices : \n";
    std::cout << "---------------------\n";
    for(int i=0; i<poll_options.size(); i++) {
        std::cout << ++i << " " << poll_options[--i] << std::endl;
    }
}
    