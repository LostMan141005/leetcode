#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class Solution {
public:  
    int divide(int dividend, int divisor) {
        if(divisor == 0) return INT_MAX;
        if(divisor == 1) return dividend;
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        int res = 0, tmp = 1;
        bool flag = (dividend > 0) ^ (divisor > 0) ? false:true;
        long long divd = labs(dividend);
        long long divr = labs(divisor);
        while(divd >= divr){
            long long temp = divr;
            tmp = 1;
            while(divd >= (temp << 1)){
                temp <<= 1;
                tmp <<= 1;
            }
            divd -= temp;
            res += tmp;
        }
        return flag ? res: -res;
    }
};

int main(){

    return 0;
}