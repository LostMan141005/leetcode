#include<iostream>
#include<string>
#include<stdlib.h>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty()) return res;
        string str[10] = {" ", "~", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> vec;
        for(int i = 0; i < digits.size(); i++){
            if(res.empty()){
                for(int j = 0; j < str[digits[i] - 48].size(); j++){
                    string strTemp;
                    strTemp += str[digits[i] - 48][j];
                    res.push_back(strTemp);
                }
            }else{
                vec.clear();
                vec = res;
                res.clear();
                for(int j = 0; j < vec.size(); j++){
                    for(int k = 0; k < str[digits[i] - 48].size(); k++){
                        string strS = vec[j];
                        strS += str[digits[i]-48][k];
                        res.push_back(strS);
                    }
                }
            }
        }
        return res;
    }
};

int main(){
    Solution su;
    string str = "104";
    vector<string> vec = su.letterCombinations(str);
    for(int i = 0; i < vec.size(); i++){
        cout<<vec[i]<<endl;
    }
    return 0;
}