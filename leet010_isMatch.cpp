#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    bool isMatchOld001(string s, string p) {
        bool res = false;
        int lens = s.length(), lenp = p.length();
        int i,j;
        for(i = 0; i < lenp; i++){
            for(j = 0; j < lens; j++){
                if(p[i] == '.'){
                    ++i;
                    continue;
                }
                if(p[i] == '*'){
                    if(p[i-1] == '.'){
                        --i;
                        continue;
                    }else if(p[i-1] == s[j]){
                        continue;
                    }else{
                        ++i;
                    }
                }
                if(p[i] == s[j]){
                    ++i;
                }else{
                    break;
                }
            }
            if(p[i] == '*' && i == lenp-1){
                lenp = i;
            }
            if(j == lens && i == lenp){
                res = true;
                break;
            }
        }
        return res;
    }
    

    bool isMatchOld002(string s, string p) {
        bool res = false;
        int lens = s.length(), lenp = p.length();
        string strS,strP;
        for(int i = 0; i < lens; i++){
            int temp = 1;
            while(s[i] == s[i+1]) {++temp; ++i;}
            strS += s[i];
            strS += temp;
        }
        for(int i = 0; i < lenp; i++){
            int j = 0;
            if(p[i] == strS[j]){
                int num = strS[j+1];
                int temp = 0;
                for(int k = i; k < lenp; ){
                    if(p[k] == p[k+1]){
                        ++i;
                        ++temp;
                    }else if(p[k+1] == '*'){
                        if(p[k] == p[k+2]){
                            k += 2;
                            continue;
                        }
                    }
                }
            }else{
                
            }
            j += 2;
        }
     
        return res;
    }
    
    
    bool isMatch(string s, string p){
        int lenS = s.length(), lenP = p.length();
        if(lenS == 0){
            if(lenP == 0 || (p[1] == '*' && isMatch(s,p.substr(2)))){
                return true;
            }else{
                return false;
            }
        }else if(lenP == 0){
            return false;
        }
        if(p[1] != '*'){
            if(p[0] == s[0] || p[0] == '.'){
                return isMatch(s.substr(1),p.substr(1));
            }else{
                return false;
            }
        }else{
            if(isMatch(s,p.substr(2))){
                return true;
            }else if(s[0] == p[0] || p[0] == '.'){
                return isMatch(s.substr(1),p);
            }else{
                return false;
            }
        }
    }
};



int main(){
    string s,p;
    Solution su;
    while(cin>>s>>p){
        cout<<su.isMatch(s,p)<<endl;
    }
    return 0;
}