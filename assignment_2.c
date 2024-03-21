#include<stdio.h>
#include<stdlib.h>

int sum(int **);

int main() {
    int sum;
    int i, j;
    int res_i, res_j;
    int n, m;
    scanf("%d %d", &n, &m);
    int height = n + 2;
    int width = m + 2;
    int **matrix;
    int max;
    matrix = (int**) malloc(sizeof(int*) * height);
    for (int i = 0; i < height; i++) {
        *(matrix + i) = (int*) malloc(sizeof(int) *width);
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            *(*(matrix + i) + j) = 0;
        }
    }
    for (int i = 1; i < height - 1; i++) {
        for (int j = 1; j < width - 1; j++) {
            scanf("%d", *(matrix + i) + j);
        }
    }
    i = 1;
    j = 1;
    max=0;
    max = *(*(matrix + i) + j - 1) + *(*(matrix + i - 1) + j) + *(*(matrix + i + 1) + j) + *(*(matrix + i) + j + 1);

    for (int i = 1; i < height - 1; i++) {
        for (int j = 1; j < width - 1; j++) {
            sum = *(*(matrix + i) + j - 1) + *(*(matrix + i - 1) + j) + *(*(matrix + i + 1) + j) + *(*(matrix + i) + j + 1);
            if (sum > max) {
                max = sum;
                res_i = i;
                res_j = j;
            }
        }
    }
    printf("%d %d", res_i, res_j);
}

//Just change the address of matrix by doing matrix = *(matrix + 1) + 1
//int func(int**arr){sum}
//max = func(matrix);
//matrix = *(matrix - 1) - 1;
//and now put the func(matrix) inside of the last double for loop
