#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class Solution {
public:
/* 
	string longestPalindromeNew(string s) {
		string str = "";
		if(s.empty()) return NULL;
		int l = 0, r = 0, maxLen = -1;
        bool flag = true;
        int temp = 1;
		for(int i = 0; i < s.size(); i++) {
			int j = 0;
			while(i - j >= 0 && i + j < s.size()) {
				if(s[i] == s[i+1]){
                    if(flag){
                        temp++;
                        r = i + 1;
                    }
                    if(temp > maxLen){
                        maxLen = temp;
                    }
                }
                if(s[i-j] == s[i+j]) {
					if(2*j + 1 > maxLen) {
						l = i - j;
						r = i + j;
						maxLen = 2*j + 1;
					}
                    if(s[i - j] != s[i]){
                        temp = 1;
                        flag = false;
                    }else{
                        flag = true;
                    }
				} else {
					break;
				}
				j++;
			}
		}
        l = r + 1 - maxLen ;
		while(l <= r) {
			str += s[l];
			l++;
		}
		return str;
	}
     */
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;
        string str = "";
        int len = s.size();
        int d = len;
        int l,r;
        for(; d > 0; d--){
            for(l = 0; l + d - 1 < len; l++){
                r = l + d - 1;
                int mid = d / 2;
                bool flag = true;
                if(d & 1){
                    for(int k = 0; k < mid; k++){
                        if(s[l+k] != s[r-k]){
                            flag = false;
                            break;
                        }
                    }
                    if(flag){
                        d = 0;
                        break;
                    }
                }else{
                    for(int k = 0; k < mid; k++){
                        if(s[l+k] != s[r-k]){
                            flag = false;
                            break;
                        }
                    }
                    if(flag){
                        d = 0;
                        break;
                    }
                }
            }
        }
        str = s.substr(l,r-l+1);
        return str;
    }
    
};



int main() {
    string str = "babad";
    Solution su;
    cout<<su.longestPalindrome(str);
	return 0;
}

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size()<=1) 
            return s;
        int min_left=0;
        int max_len=1;
        int max_right=s.size()-1;
        for (int mid=0;mid<s.size();){

            int left=mid;
            int right=mid;
            while (right<max_right && s[right+1]==s[right])
                right++; // Skip duplicate characters in the middle
            mid=right+1; //for next iter
            while (right<max_right && left>0 && s[right+1]==s[left-1]){
                right++; 
                left--;
            } // Expand the selection as long it is a palindrom
            int new_len=right-left+1; //record best palindro
            if (new_len>max_len){ 
                min_left=left; 
                max_len=new_len; 
            }
        }
        return s.substr(min_left, max_len);
    }
};

