#include <stdio.h>

int main(){
    int rate;
    int *p_rate;

    rate = 500;
    p_rate = &rate;

    printf("rate = %d\n", rate);
    *p_rate = 1000;
    printf("rate = %d\n", *p_rate);

}