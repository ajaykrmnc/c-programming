#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>

// Maximum number of data that can trasfer
#define MESSAGE_LENGTH 1024
#define PORT 8888

// Creating Macro for the socketaddr as SA
#define SA struct sockaddr

//Global Data
int socket_file_descriptor, connection;

struct sockaddr_in serveraddress, client;
char message[MESSAGE_LENGTH];

int main(){
    // Socket Creation
    socket_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_file_descriptor == -1){
        printf("Creating of Socket failed");
    }
    // Erase the memory 
    bzero(&serveraddress, sizeof(serveraddress));

    // Setting the Server Properties
    serveraddress.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Setting the port number
    serveraddress.sin_port = htons(PORT);

    // Protocol family 
    serveraddress.sin_family = AF_INET;

    connection = connect(socket_file_descriptor, (SA *)&serveraddress, sizeof(serveraddress));

    if(connection == -1){
        printf("Connection with the server failed\n");
        exit(1);
    }

    // Interacting with the server
    while(1){
        bzero(message, sizeof(message));
        printf("Enter the message you want to send to the server: ");
        scanf("%[^\n]%*c", message);
        if((strncmp(message, "end", 3)) == 0){
            write(socket_file_descriptor, message, sizeof(message));
            printf("Client Exit.\n");
        }
        // Sending the data to the server by storing the number

        ssize_t bytes = write(socket_file_descriptor, message, sizeof(message));

        // IF the number of bytes is >= 0 then data is sent

        if(bytes >= 0){
            printf("Data sned to the server successfully. !\n");
        }
        bzero(message, sizeof(message));
        // Reading the response from the server.
        read(socket_file_descriptor, message, sizeof(message));
        printf("Data received from server: %s\n", message);
    }
    // Closing the Socket Connection
    close(socket_file_descriptor);
    return 0;
}

/*
41

Breakdown of scanf("%*[^\n]%*c"):

%*[^\n] scans everything until a \n, but doesn't scan in the \n. The asterisk(*) tells it to discard whatever was scanned.
%*c scans a single character, which will be the \n left over by %*[^\n] in this case. The asterisk instructs scanf to discard the scanned character.
Both %[ and %c are format specifiers. You can see what they do here. The asterisks in both the specifiers tell scanf, not to store the data read by these format specifiers.

As @chux commented below, it will clear a single line of the stdin (Standard Input Stream) up to and including the newline character. In your case, the line with invalid input gets cleared from the stdin.

*/
