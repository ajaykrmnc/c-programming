#include <stdlib.h>
#include <stdio.h>

int main(){
    int num = 5;
    const int limit = 500;
    int const *pi;
    // if it denote to the const variable then it should be of const type

    const int *pci;

    pi = &num;
    
    pci = &limit;
    // once assigned to const number cannot changed itself
    // pci = &num;

    // we can't also change if it is assigned to the const pointer.

    printf("num - address: %p value: %d\n", &num, num);
    printf("limit - address %p value: %d\n", &limit, limit);
    printf("pi - address %p value: %p\n", &pi, pi);
    printf("pci - address: %p value: %p\n", &pci, pci);

    // but it can be assigned to another const number

    const int limit2 = 1000;
    pci = &limit2;
    // both are equivalent
    // const int *pci2 = &num;
    // *pci2 = 100;

    int num2 = 100;
    int *const cpi2 = &num;
    *cpi2 = 200;

    //third variation

    const int limit3 = 500;
    // int *const cpi3 = &limit3;

    // This is not permissible int the case for this

    // fourth variation
    // const int limit4 = 500;
    // or
    int limit4 = 500;


    const int * const cpci = &limit4;
    // cpci = &limit4; 
    
    // another variation

    // this is also not allowed
    // const int num5 = 100;
    // int *const cpi5 = &num5;




}
/*
A const number must be only assigned to const pointer

But a const pointer can be assigned to point a non-constant number

// there is clear distinction between

int const *pci and int *const pci ;


*/