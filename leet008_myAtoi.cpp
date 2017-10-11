#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

#define INT_MAX 2147483647
#define INT_MIN -2147483648


class Solution {
public:
    int myAtoiOld(string str) {
        int res = 0;
        bool flag = false;
        int i = 0, temp = 0;
        while(temp < str.size()){
            if(str[temp] == ' '){
                temp++;
            }else{
                break;
            }
        }
        while(i < str.size()){
            if(str[i+temp] == '+'){
                if(i != 0) break;
            }else if(str[i+temp] == '-'){
                if(i == 0) flag = true;
                else break;
            }else if(str[i+temp] == '.'){
                break;
            }else if(str[i+temp] >= '0' && str[i+temp] <= '9'){
                int wq = res;
                res = res*10 + (str[i+temp] - '0');
                if(wq != res/10){
                    if(flag) res = INT_MIN;
                    else res = INT_MAX;
                    break;
                }
            }else{
                break;
            }
            i++;
        }
        if(flag){
            res = 0 - res;
        }
        return res;
    }
    
    int myAtoi(string str){
        if(str.empty()) 
            return 0;
        int i = 0, res = 0;
        while(str[i] == ' ')
            i++;
        int sign = 1;
        if(str[i] == '+' || str[i] == '-'){
            sign = (str[i] == '+'?1:-1);
            i++;
        }
        while(i < str.size()){
            if(str[i] >= '0' && str[i] <= '9'){
                int temp = res;
                res = res*10 + (str[i] - '0');
                if(temp != res/10){
                    res = (sign == 1?INT_MAX:INT_MIN);
                    break;
                }
            }else{
                break;
            }
            i++;
        }
        return sign*res;
    }
};


int main(){
    Solution su;
    string str;
    while(cin>>str){
        cout<<su.myAtoi(str)<<endl;
    }
    return 0;
}
