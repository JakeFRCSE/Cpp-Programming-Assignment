#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

int islower(string& word) {
    for(int i = 0; i < word.size(); i++) {
        if(isupper(word[i])){
            return 0;
        }
    }
    return 1;
}

void tolower(string& pastestr, string& copystr) {
        for (int k = 0; k < copystr.length(); k++) {
            pastestr[k] = tolower(copystr[k]);
        }
}

void move_to_right(int start, int freq, string word, int *freqarr, string* res_word){
    for (int i = 1; i >= start; i--) {
        freqarr[i + 1] = freqarr[i];
        res_word[i + 1] = res_word[i];
    }
    freqarr[start] = freq;
    res_word[start] = word;
}

void make_res(int freq, string word, string* res_word, int* freqarr, int index) {
    if (freq == freqarr[index]) {
        string temp = word, temparr = res_word[index];
        tolower(temp, word);
        tolower(temparr, res_word[index]);
        if (temp.compare(temparr) < 0) {
            move_to_right(index, freq, word, freqarr, res_word);
        }
        else if(index <= 1){
            make_res(freq, word, res_word, freqarr, index + 1);
        }
    }
    else if (freq > freqarr[index]) {
        move_to_right(index, freq, word, freqarr, res_word);
    }
    else {
        if(index <= 1){
            make_res(freq, word, res_word, freqarr, index + 1);
        }
    }
}

void check_plural(string* words, int i, int j, string tempi, string tempj){
    if (tempi[tempi.length() - 1] == 's' && (tempi.substr(0, tempi.length() - 1).compare(tempj)) == 0){
        words[i] = words[i].substr(0, words[i].length() - 1);
        tempi = tempi.substr(0, tempi.length() - 1);
    }
}

int main() {
    string corpus;
    string *words = new string[500];
    int num_of_word = 0;
    string *res_word = new string[3];
    int freqarr[3] = {0, 0, 0};
    string tempi, tempj;
    //input
    getline(cin, corpus);
    //delete punctuations
    corpus.erase(remove(corpus.begin(), corpus.end(), '.'), corpus.end());
    corpus.erase(remove(corpus.begin(), corpus.end(), ','), corpus.end());
    //parsing
    stringstream stream(corpus);
    while(stream >> words[num_of_word]){num_of_word++;}
    //normalize
    for (int i = 0; i < num_of_word - 1; i++) {
        tempi = words[i];
        tolower(tempi, words[i]);
        for (int j = i + 1; j < num_of_word; j++) {
            tempj = words[j];
            tolower(tempj, words[j]);
            check_plural(words, i, j, tempi, tempj);
            check_plural(words, j ,i, tempj, tempi);
            if ((islower(words[i]) || islower(words[j])) && (tempi == tempj)){
                words[i] = tempi;
                words[j] = tempj;
            }
        }
    }
    //clear stopwords and count
    for (int i = 0; i < num_of_word; i++) {
        if (words[i].length() < 3) {
            words[i].clear();
        }
        if (words[i].empty() == true){
            continue;
        }
        int freq = 0;
        for (int j = i; j < num_of_word; j++) {
            if ((words[i].compare(words[j])) == 0){
                freq += 1;
                if (i != j){
                    words[j].clear();
                }
            }
        }
        make_res(freq, words[i], res_word, freqarr, 0);
    }
    for(int i = 0; i < 3; i++){
        if(freqarr[i] > 0) {
            cout<<res_word[i]<<" "<<freqarr[i]<<endl;
        }
    }
}
