#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Maximum number of bytes that can transfer and receive
#define MESSAGE_BUFFER 4096

#define PORT 8888

#define SA struct sockaddr

// Global data
char buffer[MESSAGE_BUFFER];
char message[MESSAGE_BUFFER];

int socket_file_descriptor, message_size;
socklen_t length;
const char *end_string = "end";
int quit_status;

struct sockaddr_in serveraddress, client;
/// @brief 
void processRequest(){
    // Server Properties 
    bzero(&serveraddress, sizeof(serveraddress));
    // Create a UDP Socket via PORT 8888
    socket_file_descriptor = socket(AF_INET, SOCK_DGRAM, 0);

    serveraddress.sin_addr.s_addr = htonl(INADDR_ANY);
    // Connecting via port 8888
    serveraddress.sin_port = htons(PORT);
    // Protocol Family
    serveraddress.sin_family = AF_INET;
    
    // bind server address to socket descriptor
    bind(socket_file_descriptor, (SA *)&serveraddress, sizeof(serveraddress));
    while(1){
        // Calculating the Client Datagram Length
        length = sizeof(client);
        message_size = recvfrom(socket_file_descriptor, buffer, sizeof(buffer), 0, (SA *)&client, &length);
        buffer[message_size] = '\0';
        quit_status = strcmp(buffer, end_string);
        if(quit_status == 0){
            printf("Server is Quitting\n");
            close(socket_file_descriptor);
            exit(0);
        }
        printf("Message Received from Client: %s\n", buffer);
        // Sending the response to the client

        printf("Enter reply message to the client: ");
        scanf("%[^\n]%*c", message);
        sendto(socket_file_descriptor, message, MESSAGE_BUFFER, 0, (SA *)&client, sizeof(client));
        printf("Message Send Successfully to the client.. !\n");
        printf("Waing for the Reply from client.. !\n");
    }
    // Closing the Socket File Descriptor.
    close(socket_file_descriptor);
}
int main(){
    printf("SERVER IS LISTENING THROUGH THE PORT : %d WITHIN A LOCAL SYSTEM\n", PORT);
    // Calling the process request function to process the client
    processRequest();
    return 0;
}
