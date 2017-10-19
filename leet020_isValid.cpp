#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        if(len % 2 != 0) return false;
        string strStack;
        for(int i = 0; i < len; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                strStack.push_back(s[i]);
            }else{
                if(strStack.empty()){
                    strStack.push_back(s[i]);
                    break;
                }else{
                    char back = strStack.back();
                    if((s[i] == ')' && back == '(') || (s[i] == '}' && back == '{') || (s[i] == ']' && back == '[')){
                        strStack.pop_back();
                    }else{
                        break;
                    }
                }
            }
        }
        return strStack.empty();
    }
};

int main(){

    return 0;
}