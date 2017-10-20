#include<iostream>
#include<string>
#include<stdlib.h>
#include<set>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        set<string> strSet = generateParenthesisSet(n);
        return vector<string>(strSet.begin(),strSet.end());
    }

    set<string> generateParenthesisSet(int n){
        set<string> strSet;
        if(n == 1){
            string str = "()";
            strSet.insert(str);
            return strSet;
        }
        // 在每个 str 挨个插入 () 
        // set 去除重复 string
        set<string> retSet = generateParenthesisSet(n-1);
        for(set<string>::iterator it = retSet.begin(); it != retSet.end(); it++){
            string str = *it;
            for(int i = 0; i < str.size(); i++){
                string temp = str.substr(0,i) + "()" + str.substr(i);
                strSet.insert(temp);
            }
        }
        return strSet;
    }
}; 
/* 
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParenthesisHelp(res,"",n,0);
        return res;
    }
    void generateParenthesisHelp(vector<string>& res, string str, int n, int m){
        if(n == 0 && m == 0){
            res.push_back(str);
            return;
        }
        if(m > 0){ generateParenthesisHelp(res,str+")",n,m-1); }
        if(n > 0){ generateParenthesisHelp(res,str+"(",n-1,m+1); }
    }
}; */

int main(){

    Solution su;
    int n;
    while(cin>>n){
        vector<string> strVec = su.generateParenthesis(n);
        for(int i = 0; i < strVec.size(); i++){
            cout<<strVec[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}