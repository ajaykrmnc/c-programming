#include <stdio.h>

int main(){
    int x = 4;
    void *q = &x;
    // first assigning the void pointer to int pointer

    printf("void pointer %p\n", q);
    int *p = q;
    printf("Converted %p\n", p);

    int i = *p;
    int j = *(int *)q;
    p = 0;
    p = (int *)1;
    void *r;
    printf("pointer r is %p\n",r);
    printf("pointer is %p\n", p);

    // this will give the segmentation fault
    // printf("value of pointer p is %d\n", *p);
}