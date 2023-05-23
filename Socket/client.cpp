#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    int connection_status = connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    if (connection_status == -1) {
        std::cout << "Error: connection failed" << std::endl;
        return 1;
    }
     std::cout << "client socket connected: " << std::endl;
    
    char message[] = "Hello, server!";
    send(client_socket, message, sizeof(message), 0);
    std::cout << "client msg sent success: " << std::endl;

    
    char buffer[1024] = {0};
    recv(client_socket, buffer, 1024, 0);
    std::cout << "Server response: " << buffer << std::endl;
    
    close(client_socket);
    return 0;
}