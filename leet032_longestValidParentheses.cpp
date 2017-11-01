#include<iostream>
#include<string>
#include<stdlib.h>
#include<stack>
using namespace std;

class Solution {
public:
/*     // 超时
    int longestValidParentheses(string s) {
        int maxLen = 0, len = s.size();
        for(int d = len/2 * 2; d > 0; d -= 2){
            for(int i = 0; i <= len - d; i++){
                string str = s.substr(i,d);
                if(isValidParentheses(str)){
                    return str.size();
                }
            }
        }
        return maxLen;
    }
    bool isValidParentheses(string s){
        string strStack;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                strStack.push_back(s[i]);
            }else if(s[i] == ')' && !strStack.empty()){
                strStack.pop_back();
            }else{
                strStack.push_back(s[i]);
                break;
            }
        }
        return strStack.empty();
    }  */
    
    int longestValidParentheses(string s){
        int maxLen = 0;
        stack<int> st;
        st.push(-1);
        for(int i = 0; i < s.size(); i++){
            int t = st.top();
            if(t != -1 && s[i] == ')' && s[t] == '('){
                st.pop();
                maxLen = max(maxLen,i-st.top());
            }else{
                st.push(i);
            }
        }
        return maxLen;
    }
    
};

int main(){
    Solution su;
    string str = "()()";
    cout<<su.longestValidParentheses(str)<<endl;

    return 0;
}