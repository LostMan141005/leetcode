#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    string intToRomanOld001(int num) {
        string res;
        int iN[4] = {0};
        int i = 0;
        while(num){
            iN[i++] = num%10;
            num /= 10;
        }
        i = 0;
        while(i++ < iN[3]) res+='M';
        i = 2;
        while(i >= 0){
            res += iTRoman(iN[i],i);
            i--;
        }
        return res;
    }
    string iTRoman(int num, int n){
        string str[3] = {"IVX","XLC","CDM"};
        string res;
        int i = 0;
        switch(num){
            case 0:
            case 1:
            case 2:
            case 3:
                while(i++ < num) res += str[n][0];
                break;
            case 4:
                res += str[n][0];
                res += str[n][1];
                break;
            case 5:
            case 6:
            case 7:
            case 8:
                i = 5;
                res += str[n][1];
                while(i++ < num) res += str[n][0];
                break;
            case 9:
                res += str[n][0];
                res += str[n][2];
                break;
            default:
                break;
        }
        return res;
    } 
    
    
    const static string THOUS[];
	const static string HUNDS[];
	const static string TENS[];
	const static string ONES[];
    string intToRoman(int num) {
		string result;
		result += THOUS[(int)(num/1000)%10];
		result += HUNDS[(int)(num/100)%10];
		result += TENS[(int)(num/10)%10];
		result += ONES[num%10];
		return result;
    }
    const string Solution::THOUS[]	= {"","M","MM","MMM"};
    const string Solution::HUNDS[]	= {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    const string Solution::TENS[]	= {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    const string Solution::ONES[]	= {"","I","II","III","IV","V","VI","VII","VIII","IX"};
};


int main(){
    Solution su;
    int x;
    while(cin>>x){
        cout<<su.intToRoman(x)<<endl;
    }
    return 0;
}