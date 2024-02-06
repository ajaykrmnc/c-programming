#include <stdlib.h>
#include <stdio.h>

int main(){
    char *name = (char *)malloc(18 * sizeof(char));
    printf("Enter a name ");
    scanf("%s", name);
    printf("%lu\n", sizeof(name));
}