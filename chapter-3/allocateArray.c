#include <stdio.h>
#include <stdlib.h>

int *allocateArray(int size, int value){
    int *arr = (int *)malloc(size * sizeof(int));
    for(int i = 0; i < size; ++i){
        arr[i] = value;
    }
    return arr;
}
// int *allocateArray2(int size,int value){
//     int arr[size];
//     for(int i = 0; i < size; ++i){
//         arr[i] = value;
//     }
//     return &arr;
// }
void allocateArray3(int **arr, int size, int value){
    *arr = (int *)malloc(size * sizeof(int));
    for(int i = 0; i < size; ++i){
        // this is wrong *arr[i]
        // *(*arr + i) = value;
        (*arr)[i] = value;
    }
}

int main(){
    int *vector = NULL;
    // vector = allocateArray(5,45);
    // for(int i = 0; i < 5; i++){
    //     printf("%d ", vector[i]);
    // }
    allocateArray3(&vector, 10, 45);
    for(int i = 0; i < 10; i++){
        printf("%d ", vector[i]);
    }
    printf("\n");
    return (EXIT_SUCCESS);
}