#include <stdio.h>
#include <fcntl.h>
int main(){
    int file_descriptor;
    char filename[255];
    printf("Enter the filename: ");
    scanf("%s", filename);
    file_descriptor = open(filename, O_RDONLY);
    /*
    A file descriptor is an integer value that identifies the open file in a process. This program creates a new file with the given permissions set.
    */
    // Setting Permission to Read Only for the file
    /*
        On Success: It return any value other than -1
    */
   if(file_descriptor != -1){
        printf("%s Opened Successfully!", filename);
   }else{
        printf("Unable to open %s", filename);
   }
   return 0;
}