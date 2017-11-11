#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1){
            return "1";    
        }
        string str = countAndSay(n-1);
        string ss;
        for(int i = 0; i < str.size(); ++i){
            int t = 1;
            while(i < str.size()-1 && str[i] == str[i+1]){
                ++t;
                ++i;
            }
            ss += (t+48);
            ss += str[i];
            
        }
        return ss;
    }
};


int main(){
    Solution su;
    cout<<su.countAndSay(5)<<endl;
    return 0;
}