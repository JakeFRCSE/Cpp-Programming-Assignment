#include<stdio.h>

float func(int);

int main() {
    int n;
    scanf("%d", &n);
    printf("%.5f", func(n));

}

float func(int n) {
    if (n == 0) {
        return 1.0;
    }
    else {
        return 1 + (1 / func(n - 1));
    }
}
