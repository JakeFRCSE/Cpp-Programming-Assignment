#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;


int main()
{
    map<string, int> myMap;
    map<string, int>::iterator it, tempIt;
    //ifstream ifs("02.inp", ios::in);
    string line;
    string token;


        getline(cin, line);
        for(int i=0;i<line.length(); i++) {
            if(!isalpha(line[i])) line[i]=' ';
        }

        istringstream iss(line);
        while(iss>>token) {
            if(token.length() >= 3) {
                it = myMap.find(token);
                if(it != myMap.end()) { //something found
                    it->second++;
                }
                else { // nothing found
                    myMap.insert(pair<string,int>(token, 1));
                }

            }
        }


    for (int i = 0; i < 3; i++){
        int tempInt = 0;
        string tempString;
        for(it = myMap.begin(); it != myMap.end(); it++){
        if (it->second > tempInt) {
            tempString = it->first;
            tempInt = it->second;
        }
    }
    cout<<tempString<<" "<<tempInt<<endl;
    myMap.erase(tempString);
    }


    return 0;
}
