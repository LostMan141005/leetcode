#include <iostream>  
#include <cstring>  
using namespace std;  
  
#define MAX 101  
#define max(a,b) (a)>(b)?(a):(b)  
string findLongestPalindrome(string &s);  
int main()  
{  
    string s;     
    while (cin>>s)  
    {  
        cout<<findLongestPalindrome(s);

        // int f[MAX][MAX];  
        // memset(f,0,sizeof(f));  
        // for (int i=s.length()-1;i>=0;i--)  
        // {  
            // f[i][i]=1;  
            // for (int j=i+1;j<s.length();j++)  
                // if (s[i]==s[j])  
                    // f[i][j]=f[i+1][j-1]+2;  
                // else  
                    // f[i][j]=max(f[i][j-1],f[i+1][j]);  
        // }  
        // cout<<f[0][s.length()-1]<<endl;  
        
    }  
    return 0;  
} 
string findLongestPalindrome(string &s)  
{  
    if(s.size() <= 1) return s;
    const int length=s.size();  
    int maxlength=0;  
    int start;  
    bool P[50][50]={false};  
    for(int i=0;i<length;i++)//初始化准备  
    {  
        P[i][i]=true;  
        if(i<length-1&&s.at(i)==s.at(i+1))  
        {  
            P[i][i+1]=true;  
            start=i;  
            maxlength=2;  
        }  
    }  
    for(int len=3;len<=length;len++)//子串长度  
        for(int i=0;i<=length-len;i++)//子串起始地址  
        {  
            int j=i+len-1;//子串结束地址  
            if(P[i+1][j-1]&&s.at(i)==s.at(j))  
            {  
                P[i][j]=true;  
                maxlength=len;  
                start=i;  
            }  
        }  
    if(maxlength>=2)  
        return s.substr(start,maxlength);  
    return NULL;  
}  