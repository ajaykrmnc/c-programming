#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *pc = (char *) malloc(6);
    for(int i = 0; i < 8; i++){
        pc[i] = 0;
    }
}