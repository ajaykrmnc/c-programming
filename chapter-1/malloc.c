#include <stdio.h>
#include <stdlib.h>

int main(){
    int *pi;
    pi = (int *)malloc(sizeof(int));
    *pi = 5;
    printf("*pi: %d\n", *pi);
    free(pi);
}

