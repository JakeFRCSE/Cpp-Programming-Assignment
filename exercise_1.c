#include<stdio.h>
#include<math.h>

int max_find(int, int, int*);
int max(int, int);

int main() {
    int n;
    scanf("%d", &n);
    int i = 0;
    int arr[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int max = max_find(0, n - 1, arr);
    printf("%d", max);
}


int max_find(int low, int high, int *arr) {
    if (low < high) {
        return max(max_find(low, (low + high) / 2, arr), max_find(((low + high) / 2) + 1, high, arr));
    }
    else if (low == high) {
        return arr[low];
    }
}

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    else if (a < b) {
        return b;
    }
}
