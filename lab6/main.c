#include <stdio.h>

int _sum(int x, int y) {
    return x + y;
}
int _subtract(int x, int y) {
    return x - y;
}
int _multiply(int x, int y) {
    return x * y;
}
int _divide(int x, int y) {
    return x / y;
}
int _power(int x, int y) {
    if(y == 1) return x;
    int num = x;
    num = _power(num, --y);
    num *= x;
    return num;
}

int main() {
    int x, y, choice;
    int (*operate[5])(int, int);
    operate[0] = _sum;
    operate[1] = _subtract;
    operate[2] = _multiply;
    operate[3] = _divide;
    operate[4] = _power;
    
    printf("分別輸入兩個整數x,y:");
    scanf("%d%d", &x, &y);
    
    printf("輸入 0:+, 1:-, 2:*, 3:, 4:^ :");
    scanf("%d", &choice);
    
    printf("運算結果:%d", operate[choice](x, y));
    return 0;
}
