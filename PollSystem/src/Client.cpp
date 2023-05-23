#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void printServerMessage(char[], int&);
int getClientInput(int);

int main() {

    int client_socket, bytes_read, size = 1024;
    char poll_message[size];
    static int choice_count = 0;
    std::string outgoing_message;

    client_socket = socket(AF_INET, SOCK_STREAM, 0);    
    sockaddr_in server_address;
    std::memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    int connection_status = connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    if (connection_status == -1) {
        std::cout << "Error: connection failed" << std::endl;
        exit(1);
    }
    
    bytes_read = recv(client_socket, poll_message, size-1, 0);
    printServerMessage(poll_message, choice_count);
    int client_input = getClientInput(choice_count);

    outgoing_message = std::to_string(client_input);
    send(client_socket, &outgoing_message, sizeof(outgoing_message), 0);

    std::cout << "Choice sent success" << std::endl;
    close(client_socket);
}

void printServerMessage(char receivedMessage[], int &choice_count) {

    if(strlen(receivedMessage) == 0) {
      std::cout << "No message received from server\n" << std::endl;
      exit(1);
    }

    for(int i=0; i<strlen(receivedMessage); i++) {
      if(receivedMessage[i] == '\n') {
        //count the choices
        choice_count++;
        std::cout << "\n" << choice_count << " ";
      } else {
          std::cout << receivedMessage[i];
      }
    }

    //if no choices received, "poll has ended" case
    if(choice_count == 0) {
        std::cout << std::endl;
        exit(1);
    }
    std::cout << std::endl;
}

int getClientInput(int choice_count) {
  
    int input;
    while(true) {
      std::cout << "Choose an option: " << std::endl;
      std::cin >> input;
      if(input <= choice_count && input > 0) {
          return input;
      }
      else {
          std::cout << "Wrong input" << std::endl;
          return getClientInput(choice_count);
      }      
    }
}
