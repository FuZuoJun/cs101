#include <stdlib.h>
#include <stdio.h>
int i = 0;
FILE* Honai;

char rec_dec(char* str) {
    i != 0 ? printf(",%c", *str): printf("%c", *str);
    if(!(*str)) return 0;
    i++;
    rec_dec(str+1);
    return 0;
}

void towerOfHanoi (int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        Honai = fopen("honai.txt", "a+");
        fprintf(Honai, "\n Move disk 1 from  %c to  %c", from_rod, to_rod);
        fclose(Honai);
        return ;
    }
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
    Honai = fopen("honai.txt", "a+");
    fprintf(Honai, "\n Move disk %d from  %c to  %c", n, from_rod, to_rod);
    fclose(Honai);
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}

int multiplication(int i, int j) {
    printf("%d*%d=%2d ", i, j, i*j);
    if(j == 9) {
        if(i == 9) return 0;
        printf("\n");
        i++;
        j = 0;
        return multiplication(i ,j+1);
    }
    multiplication(i ,j+1);
    return 0;
}

int main() {
    char s[] = "QZ 3 HELLO!";
    printf("Function Result#1.----------------\n");
    rec_dec(s);
    printf("\nFunction Result#2.----------------\n");
    printf("結果見txt檔");
    towerOfHanoi(16, 'A', 'B', 'C');
    printf("\nFunction Result#3.----------------\n");
    multiplication(1,1);
    return 0;
}