#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
int main(){
    char filename[255];
    // Asking the Input from a User.
    printf("Enter the filename to open:\n");
    scanf("%[^\n]%*c", filename);
    int file_descriptor = open(filename, O_WRONLY | O_CREAT, 0777);// Opening File in Write mode with Create if not exist.
    if(file_descriptor == -1){
        perror("FInename not Found");
        exit(1);
    }
    char content[1024];
    printf("Enter the content to write on a given file: ");
    // User Input to write into the file
    scanf("%[^\n]%*c", content);
    int size = write (file_descriptor, content, strlen(content));
    printf("%d", size);
    close(file_descriptor);
    return 0;
}
