#include<iostream>
using namespace std;

class score{
private:
    int total_score;
    int index[8];
    int scores[8];
public:
    void sort_scores();
    int cal_total_score();
    void show_indices();
    void sort_indices();
    friend istream& operator>>(istream& is, score& a);
};

void score::sort_scores(){
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8 - i - 1; j++) {
            if (scores[j] < scores[j + 1]) {
                int temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;
                temp = index[j];
                index[j] = index[j + 1];
                index[j + 1] = temp;
            }
        }
    }
}

int score::cal_total_score() {
    total_score = 0;
    for (int i = 0; i < 5; i++) {
        total_score += scores[i];
    }
    return total_score;
}

void score::show_indices(){
    for (int i = 0; i < 5; i++) {
        cout<<index[i]<<" ";
    }
}

void score::sort_indices(){
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5 - i - 1; j++) {
            if (index[j] > index[j + 1]) {
                int temp = index[j];
                index[j] = index[j + 1];
                index[j + 1] = temp;
            }
        }
    }
}

istream& operator>>(istream& is, score& arr) {
    for (int i = 0; i < 8; i++) {
        is>>arr.scores[i];
        arr.index[i] = i + 1;
    }
    return is;
}

int main() {
    score arr;
    cin>>arr;
    arr.sort_scores();
    cout<<arr.cal_total_score()<<endl;
    arr.sort_indices();
    arr.show_indices();
}
