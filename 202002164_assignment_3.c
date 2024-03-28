#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main() {
    //declaration & scan
    int n, k;
    scanf("%d %d", &n, &k);
    int ID[n], height[n];
    float score[n], weight[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %f %d %f", &ID[i], &weight[i], &height[i], &score[i]);
    }
    //make binary file as write mode
    FILE *fp;
    fp = fopen("test.bin", "w");
    //write down the values of input
    for (int i = 0; i < n; i++) {
        fwrite(score+i, sizeof(int), 1, fp);
        fwrite(ID+i, sizeof(int), 1, fp);
        fwrite(weight+i, sizeof(float), 1, fp);
        fwrite(height+i, sizeof(float), 1, fp);
    }
    //close the file
    fclose(fp);
    //open the binary file as read mode
    fp = fopen("test.bin", "r");
    //move to the k-th element
    fseek(fp, k, SEEK_SET);
    //declaration for the result
    int res_ID, res_height;
    float res_weight, res_score;
    //read the values in order
    fread(&res_score, sizeof(float), 1, fp);
    fread(&res_ID, sizeof(int), 1, fp);
    fread(&res_weight, sizeof(float), 1, fp);
    fread(&res_height, sizeof(int), 1, fp);
    //show the result
    printf("%0.1f %d %0.1f %d", res_score, res_ID, res_weight, res_height);
    //close the file
    fclose(fp);
}
