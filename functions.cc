#include "functions.hpp"
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
using namespace std;

vector<vector<string>> readData(string sourceName) {
    ifstream file;
    vector<vector<string>> convertedFile;
    string rowContent;
    vector<string> rowStrings;
    file.open(sourceName);
    if (!file.is_open()) {
        cout<<"Error opening file"<<endl;
    }
    else {
        while(getline(file, rowContent,'\n')) {
            rowStrings.push_back(rowContent);
        }
    }
    file.close();
    
    for (size_t i = 0; i < rowStrings.size(); i++) {
        convertedFile.push_back(utilities::get_substrs(rowStrings[i], ','));
    }
    return convertedFile;
    
}

//find the longest consecutive number of target STR.
vector<int> MatchSTR(string input, vector<vector<string>> targetSTR) {
    string tarSTR1 = targetSTR[0][1];
    string tarSTR2 = targetSTR[0][2];
    string tarSTR3 = targetSTR[0][3];
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int cur_count1= 0;
    int cur_count2= 0;
    int cur_count3= 0;
    vector<int> countLongest;
    
    for (size_t i = 0; i < input.length(); i ++) {
        unsigned long k = i;
        while (k < input.length() - tarSTR1.length()){
            if (input.substr(k,k + tarSTR1.length()).compare(tarSTR1) == 0) {
                cur_count1++;
                k = k + tarSTR1.length();
            }
            if (cur_count1 > count1) {
                count1 = cur_count1;
                cur_count1 = 0;
            }
        }
    }
    for (size_t j = 0; j < input.length(); j ++) {
        unsigned long k = j;
        while (k < input.length() - tarSTR2.length()){
            if (input.substr(k,k + tarSTR2.length()).compare(tarSTR2) == 0) {
                cur_count2++;
                k = k + tarSTR2.length();
            }
            if (cur_count2 > count1) {
                count2 = cur_count1;
                cur_count2 = 0;
            }
        }
    }
    for (size_t q = 0; q < input.length(); q ++) {
        unsigned long k = q;
        while (k < input.length() - tarSTR3.length()){
            if (input.substr(k,k + tarSTR3.length()).compare(tarSTR3) == 0) {
                cur_count3++;
                k = k + tarSTR3.length();
            }
            if (cur_count3 > count3) {
                count3 = cur_count3;
                cur_count3 = 0;
            }
        }
    }
    
    countLongest.push_back(cur_count1);
    countLongest.push_back(cur_count2);
    countLongest.push_back(cur_count3);
    /*
    for (size_t tarnum = 1; tarnum < 4; tarnum++) {
        int j = 0;
        while ( j < input.length() - targetSTR[1].length()) {
            for (size_t k = 0; k < targetSTR[1].length(); k++) {
                temp = input;
                if (temp.substr(k,k+targetSTR[1].length()).compare(targetSTR[1]) == 0) {
                    if (temp[k] == temp[k+targetSTR[1].length()]) {
                        count++;
                    }
                    else if (temp[k] != temp[k+targetSTR[1].length()]){
                        count++;
                        countLongest[tarnum - 1] = count;
                    }
                }
            }
            j = j + targetSTR[tarnum].length();
        }
        
    }
     */
    return countLongest;
    
}




