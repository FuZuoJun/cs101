#include <stdio.h>
#include <stdlib.h>

typedef struct array_list {
    int n;
	int* (*list_get_int_array)(int);
	void (*list_set_value)(int*, int);
	void (*list_print_array)(int*, int);
} array_list_t;

int* get_int_array(int n) {
    return (int*)calloc(n, sizeof(int));
}

void set_value(int* p, int v) {
    *p = v;
}

void print_array(int* p, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        if(i < n - 1) {
            printf("%d, ", *p+i);
        }else {
            printf("%d", *p+i);
        }   
    }
    printf("]");
}    

char* func(char a[], char b[]) {
	int len_a = 0;
	int len_b = 0;
	while(a[len_a++]);
	while(b[len_b++]);
	char* ptr = (char*)calloc(len_a + len_b - 1, sizeof(char));
	for(int i = 0; i < len_a - 1; i++) {
		ptr[i] = a[i];
	}
	for(int i = 0; i < len_b - 1; i++) {
		ptr[len_a - 1 + i] = b[i];
	}
	ptr[len_a + len_b - 1] = '\0';
	return ptr;
}

char* add_str_func(char a[], char b[], char* (*func_ptr)(char*, char*)) {
	return func_ptr(a, b);
}

int main() {
    printf("No.1------------------------------\n");
    int n = 10;
    int* ip = get_int_array(n);
    for (int i = 0; i < n; i++) {
        set_value(ip+i, i+1);
    }
    print_array(ip, n);
    
    printf("\nNo.2------------------------------\n");
    array_list_t Func;
	Func.list_get_int_array = get_int_array;
	Func.list_set_value = set_value;
	Func.list_print_array = print_array;
	Func.n = 20;
	int* ptr = Func.list_get_int_array(Func.n);
	for(int i = 0; i < Func.n; i++) {
		Func.list_set_value(ip + i, i + 1);
	}
	Func.list_print_array(ip, Func.n);
	
	printf("\nNo.3------------------------------\n");
	char a[] = "IU!IU!";
	char b[] = "@CGU";
	printf("add_str_func = %s\n", add_str_func(a, b, func));
    return 0;
}
