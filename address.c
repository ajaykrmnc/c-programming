#include <stdio.h>

int main(){
    int a;
    int *aPtr;

    a = 7;
    aPtr = &a;

    printf("The address of a is %p\n The value of aPter is %p", &a, aPtr);
    printf("\n\nThe value of a is %d\n The value of *aPter is %d",a, *aPtr);
    printf("\n\n Showing that * and & are inverse of each other. \n & *aPter = %p\n *&aPtr = %p\n", &*aPtr, *&aPtr);
}