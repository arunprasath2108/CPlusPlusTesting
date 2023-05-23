#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

int main() {
    
    int serverSocket, newsocket, portNumber;
    char message[256];
    struct sockaddr_in serverAddress, clientAddress;
    socklen_t clilen;
    int n;

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    std::cout << "socket created in server " << std::endl;
    if (serverSocket < 0) {
        std::cerr << "Error opening socket.\n";
        exit(1);
    }

    std::memset(&serverAddress, 0, sizeof(serverAddress));
    portNumber = 8080;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(portNumber);

    if(bind(serverSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) < 0) {
        std::cerr << "Error on binding.\n";
        exit(1);
    }
    std::cout << "binded success: " << std::endl;

    listen(serverSocket, 5);
    clilen = sizeof(clientAddress);
    std::cout << "client address size: " << clilen << std::endl;

    newsocket = accept(serverSocket, (struct sockaddr *) &clientAddress, &clilen);
    if (newsocket < 0) {
        std::cerr << "Error on accept.\n";
        exit(1);
    }

    n = read(newsocket, message, 255);
    if (n < 0) {
        std::cerr << "Error reading from socket.\n";
        exit(1);
    }
    std::cout << "Message from client: " << message << std::endl;

    n = write(newsocket, "I got your message.", 18);
    if (n < 0) {
        std::cerr << "Error writing to socket.\n";
        exit(1);
    }

    close(newsocket);
    close(serverSocket);

    return 0;
}























//what is client-server comm. (wht/why/where/how)
//where it is used
//how to include thread in client-server comm.



//1 - for listening for incomming conn.
//2 - for new client request handling
//3 - 
