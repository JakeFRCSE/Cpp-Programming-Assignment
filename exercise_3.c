#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int ID[n];
    float score[n], weight[n];
    int  height[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %f %d %f", &ID[i], &weight[i], &height[i], &score[i]);
    }
    FILE *fp;
    fp = fopen("test.bin", "w");
    for (int i = 0; i < n; i++) {
        fwrite(ID+i, 4, 1, fp);
        fwrite(weight+i, 4, 1, fp);
        fwrite(height+i, 4, 1, fp);
        fwrite(score+i, 4, 1, fp);
    }
    fclose(fp);
    fp = fopen("test.bin", "r");
    fseek(fp, k, SEEK_SET);
    int res;
    fread(&res, 4, 1, fp);
    printf("%d", res);
    fclose(fp);
}
