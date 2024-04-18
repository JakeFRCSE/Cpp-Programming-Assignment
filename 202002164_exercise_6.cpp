#include<iostream>
#include<fstream>
using namespace std;


int main(){
    int n, k;
    cin>>n>>k;
    int ID[n], height[n];
    float score[n], weight[n];
    for (int i = 0; i < n; i++){
        cin>>ID[i]>>weight[i]>>height[i]>>score[i];
    }
    ofstream file("test.bin", ios::binary | ios::out);
    if(file.is_open()){
        for (int i = 0; i < n; i++) {
            file.write((char*)(score+i), sizeof(float));
            file.write((char*)(ID+i), sizeof(int));
            file.write((char*)(weight+i), sizeof(float));
            file.write((char*)(height+i), sizeof(int));
        }
    }
    file.close();
    ifstream mfile("test.bin", ios::binary | ios::in);
    if(mfile.is_open()){
        int res_ID, res_height;
        float res_weight, res_score;
        mfile.seekg(k, ios::beg);
        mfile.read((char*)&res_score, sizeof(int));
        mfile.read((char*)&res_ID, sizeof(int));
        mfile.read((char*)&res_weight, sizeof(float));
        mfile.read((char*)&res_height, sizeof(float));
        cout<<res_score<<" "<<res_ID<<" "<<res_weight<<" "<<res_height<<endl;
    }
    mfile.close();
}
