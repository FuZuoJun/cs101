#include <stdio.h>
 
int setMyBit(int a, int b) {
    a = (1 << b) | a;
    return a;
}

int clearMyBit(int a, int b) {
    a = ( (1 << b) - 1) & a;
    return a;
}

int inverseMyBit(int a, int b) {
    a = (1 << b) ^ a;
    return a;
}

int main() {
    int a = 1;
    int b = 3;
    int c = a;
    printf("setMyBit(%d, %d) = %d\n", c, b, setMyBit(a, b));
    c = a;
    printf("clearMyBit(%d, %d) = %d\n", c, b, clearMyBit(a, b));
    c = a;
    printf("inverseMyBit(%d, %d) = %d\n", c, b, inverseMyBit(a, b));
    c = a;
    return 0;
}
