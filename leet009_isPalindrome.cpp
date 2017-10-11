#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return 0;
        int y = 0, temp = x;
        while(temp != 0){
            y = y*10 + temp%10;
            temp /= 10;
        }
        return x == y ? true:false;
    }
};


int main(){
    
    Solution su;
    int x;
    while(cin>>x){
        cout<<su.isPalindrome(x)<<endl;
    }
    return 0;
}