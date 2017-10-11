#include<iostream>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

// class Solution {
// public:
    // int reverse(int x) {
        // int res = 0;
        // bool flag = false;
        // if(x < 0){
            // flag = true;
            // x = 0 - x;
        // }
        // char str[12];
        // sprintf(str,"%d",x);
        itoa(x,str,10);
        // int len = strlen(str);
        // int l = 0, r = len -1;
        // while(l < r){
            // swap(str[l],str[r]);
            // l++;
            // r--;
        // }
        // long ll = atol(str);
        // if(ll > 2147483647){
            // res = 0;
        // }else{
            // res = ll;
            // if(flag)
                // res = 0 - ll;
        // }
        // return res;
    // }
// };

class Solution {
public:
    int reverse(int x) {
     int n=1;
        long long int ans=0;
        if(x<0)
        {
            x=x*-1;
            n=-1;
        }
        while(x)
        {
            ans=ans*10+x%10;
            x=x/10;
        }
        
        if(n*ans>=INT_MIN && n*ans<=INT_MAX) return n*ans;
        else return 0;
    }
};

class Solution {
public:
    int reverse(int x) {
         int ans = 0;
        while (x) {
            int temp = ans * 10 + x % 10;
            if (temp / 10 != ans)
                return 0;
            ans = temp;
            x /= 10;
        }
        return ans;
    }
};


int main(){
    Solution su;
    int x;
    // cout<<INT_MAX<<endl<<INT_MIN<<endl;
    while(cin>>x){
        cout<<su.reverse(x)<<endl;
    }
    return 0;
}