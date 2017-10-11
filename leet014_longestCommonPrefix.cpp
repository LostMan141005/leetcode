#include<iostream>
#include<string>
#include<stdlib.h>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        if(len == 0) return "";
        if(len == 1) return strs[0];
        string res = "";
        for(int j = 0;j != -1; j++){
            for(int i = 0; i < len-1; i++){
                if(j == strs[i].size()){
                    j = -2;
                    break;
                }
                if(strs[i][j] != strs[i+1][j]){
                    j = -2;
                    break;
                }
            }
            if(j != -2){
                res += strs[0][j];
            }
        }
        return res;
    }
    
/*     
    string longestCommonPrefix(vector<string>& strs) {
      if(strs.empty())return "";
            for(auto j=0;j<strs[0].size();j++)
                 for(auto i=1;i<strs.size();i++)
                     if(strs[i][j]!=strs[0][j])
                         return strs[0].substr(0,j);
        return strs[0];       
    }
     */
};


int main(){
    Solution su;
    vector<string> str;
    str.push_back("a");
    str.push_back("abc");
    cout<<su.longestCommonPrefix(str)<<endl;
    return 0;
}