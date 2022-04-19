#include <stdio.h>

int num_swap(int* i, int* j) {
    int tmp;
    tmp = *i;
    *i = *j;
    *j= tmp;
    //printf("In function, i = %d, j = %d\n", *i, *j);
}

int array_swap(int source[], int dest[], int size) {
    int tmp;
    for(int i = 0; i < size; i++) {
        tmp = source[i];
        source[i] = dest[i];
        dest[i] = tmp;
    }
}

int array_print(int array[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if(i < size - 1) {
            printf(", ");
        } else {
            printf("");
        }
    }
    printf("]\n");
}

char* string_copy(char str[]) {
    int size = 0;
    while (str[size]) size++;
    char* ptr = (char*)calloc(1, size);
    for (int i = 0; i < size; i++) {
        *(ptr+i) = str[i];
    }
    return ptr;
}

int main() {
    int n, m;
    n = 1;
    m = 2;
    int size = 10;
    int source[10] = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int dest[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    printf("Function.1 --------------------------\n");
    num_swap(&n,&m);
    printf("After swap, n = %d, m = %d\n", n, m);
    printf("Function.2 --------------------------\n");
    array_swap(source, dest, size);
    printf("After swap array, source array = [");
    array_print(source, size);
    printf("After swap array, dest array = [");
    array_print(dest, size);
    printf("Function.3 --------------------------\n");
    char str[] = "IU!IU!IU!IU!";
    char* copy_string = string_copy(str);
    printf("Copy String = %s\n", copy_string);
    free(copy_string);
    return 0;
}
