#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>

// Maximum number of bytes that cna transfer and receive.
#define MESSAGE_BUFFER 4096

#define PORT 8888
// Creating Macro for the sokcetaddr as SA

#define SA struct sockaddr

// Global Data
char buffer[MESSAGE_BUFFER];
char message[MESSAGE_BUFFER];

int socket_file_descriptor, n;
int size = 0;
int quit_status;
const char *end_string = "end";

struct sockaddr_in serveraddress;

void sendRequest(){
    // Setting the properties to connect with server
    bzero(&serveraddress, sizeof(serveraddress));
    // Working with Localhost Address
    serveraddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    // Connecting via port 8888
    serveraddress.sin_port = htons(PORT);

    // Protocol family
    serveraddress.sin_family = AF_INET;

    // creating the datagrapm socket
    socket_file_descriptor = socket(AF_INET, SOCK_DGRAM, 0);    

    // Establishing a connection with the server
    if(connect(socket_file_descriptor, (SA *)&serveraddress, sizeof(serveraddress)) < 0){
        printf("\n Something went wrong Connection failed\n");
        exit(1);
    }

    while(1){
        printf("Enter  a message you want to send to the server: ");
        scanf("%[^\n]%*c", message);
        quit_status = strcmp(message, end_string);
        if(quit_status == 0){
            sendto(socket_file_descriptor, message, MESSAGE_BUFFER, 0, (SA *)NULL, sizeof(serveraddress));
            printf("Client work is done. !\n");
            exit(0);
        }else{
            sendto(socket_file_descriptor, message, MESSAGE_BUFFER, 0, (SA *)NULL, sizeof(serveraddress));
            printf("Message sent successfully to the server: %s\n");
            printf("Waiting for the Response from Server... !\n");
        }
        printf("Message Received From Server: ");
        recvfrom(socket_file_descriptor, buffer, sizeof(buffer), 0, (SA *)NULL, sizeof(serveraddress));
        printf("%s\n", buffer);
    }
    close(socket_file_descriptor);

}
int main(){
    printf("Client is establishing a connection with server through port: %d\n", PORT);
    // Calling the Send Request to send a request to the server
    sendRequest();
    return 0;
}