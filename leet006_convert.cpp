#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(s.size() <= 2 || numRows == 1)
            return s;
        string str = "";
        int width = 2 * numRows - 2;
        int len = s.size();
        for(int i = 0; i < numRows; i++){
            for(int j = i; j < len; j += width){
                if(i == 0 || i == numRows - 1){
                    str += s[j];
                }else{
                    str += s[j];
                    if(j + (numRows - 1 - i)*2 < len)
                        str += s[j + (numRows - 1 - i)*2];
                }
            }
        }
        return str;
    }
    
    
    public String convert(String s, int nRows) {
        char[] c = s.toCharArray();
        int len = c.length;
        StringBuffer[] sb = new StringBuffer[nRows];
        for (int i = 0; i < sb.length; i++) sb[i] = new StringBuffer();
        
        int i = 0;
        while (i < len) {
            for (int idx = 0; idx < nRows && i < len; idx++) // vertically down
                sb[idx].append(c[i++]);
            for (int idx = nRows-2; idx >= 1 && i < len; idx--) // obliquely up
                sb[idx].append(c[i++]);
        }
        for (int idx = 1; idx < sb.length; idx++)
            sb[0].append(sb[idx]);
        return sb[0].toString();
    }

};


int main(){
    
    return 0;
}