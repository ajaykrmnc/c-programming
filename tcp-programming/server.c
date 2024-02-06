#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#define MESSAGE_LENGTH 1024 // Maximum number of data can transfer
#define PORT 8888
#define SA struct sockaddr // Creating Macro for the socketadd as SA

struct sockaddr_in serveraddress, client;
socklen_t length;
int socket_file_descriptor, connection, bind_status, connection_status;
char message[MESSAGE_LENGTH];

int main(){
    // Creating the socket
    socket_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_file_descriptor == -1){
        printf("Socket creation failed.!\n");
        exit(1);
    }
    // Erases the memory
    bzero(&serveraddress, sizeof(serveraddress));

    // Server Properties
    serveraddress.sin_addr.s_addr = htonl(INADDR_ANY);
    
    // Setting the port number
    serveraddress.sin_port = htons(PORT);

    // Protocal family
    serveraddress.sin_family = AF_INET;

    //Binding the newly created socket with the given IP Address
    bind_status = bind(socket_file_descriptor, (SA *)&serveraddress, sizeof(serveraddress));

    if(bind_status == -1){
        printf("Socket binding failed.!\n");
        exit(1);
    }

    // Server is listeing for new creation
    connection_status = listen(socket_file_descriptor, 5);
    if(connection_status == -1){
        printf("Socket is unable to listen for new connnection!\n");
        exit(1);
    }else{
        printf("Socket is listening for new connection: \n");
    }
    length = sizeof(client);

    connection = accept(socket_file_descriptor, (SA *)&client, &length);
    if(connection == -1){
        printf("Server is unable to accept the data from the client");
        exit(1);
    }
    // Communication Establishment
    while(1){
        bzero(message, MESSAGE_LENGTH);
        read(connection, message, sizeof(message));
        if(strncmp("end", message, 3) == 0){
            printf("Client Exited.\n");
            printf("Server is Exiting..!\n");
            break;
        }
        printf("Data received from client: %s\n", message);
        bzero(message, MESSAGE_LENGTH);
        printf("Enter the message you want to send to the client: ");
        scanf("%[^\n]%*c", message);
        // Sending the data to the server by storing the number of byes transferred in bytes variables
        ssize_t bytes = write(connection, message, sizeof(message));

        // If the number of bytes is >= 0 then the date is sent
        if(bytes >= 0){
            printf("Data successfullly sent to the client!\n");
        }
    }
    // Closing the Socket Connection
    close(socket_file_descriptor);
    return 0;
}