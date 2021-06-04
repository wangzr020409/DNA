#include <iostream>
#include <string>
#include <vector>

#include "functions.hpp"
#include "utilities.hpp"
using namespace std;
int main(int argc, char* argv[]) {
    
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " [input_file] [dna_sequence]"
              << std::endl;
    return 1;
  }
    argc = 3;
    string filename = argv[1];
    string DNA_sequence = argv[2];

    
    vector<vector<string>> dnaInfo = readData(filename);
    
    vector<int> maxNumSTR = MatchSTR(DNA_sequence, dnaInfo);
    
    int count = 0;
    int rowNum = 0;
    
    for (size_t row = 1; row < dnaInfo.size();row++) {
        if (maxNumSTR[0] == stoi(dnaInfo[row][1]) && maxNumSTR[1] == stoi(dnaInfo[row][2]) && maxNumSTR[2] == stoi(dnaInfo[row][3])) {
            count++;
            rowNum = row;
            
        }
    }
    if (count == 1) {
        cout<<dnaInfo[rowNum][0]<<endl;
    }
    else if (count == 0 || count > 1){
        cout<<"No match"<<endl;
    }

    
    //check the first number.

    

    //cout<<finalMatch<< endl;

  return 0;
}

