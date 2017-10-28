#include<iostream>
#include<string>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include <functional>
#include <numeric>
#include<map>
using namespace std;

class Solution {
public:

/*     vector<int> findSubstring(string s, vector<string>& words) {
        if(s.empty() || words.empty()) return vector<int>();
        if(s.size() < words.front().size()*words.size()) return vector<int>();
        vector<int> res;
        sort(words.begin(),words.end());
        do{
            
            string str = accumulate(words.begin(),words.end(),string(""));
            int pos = 0;
            while((pos = s.find(str,pos)) != string::npos){
                res.push_back(pos);
                ++pos;
            } 
        }while(next_permutation(words.begin(),words.end()));
        return res;
    }
  */   
    
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s.empty() || words.empty()) return vector<int>();
        if(s.size() < words.front().size()*words.size()) return vector<int>();
        vector<int> res;
        map<string,int> mapWords;   // 统计 words 中每个词出现的次数，每个词可能出现多次
        for(int i = 0; i < words.size(); i++){
            mapWords[words[i]]++;
        }
        int numWords = words.size();   // words 中词的总数
        int lenWord = words[0].size(); // words 中单个词的长度
        int lenS = s.size();           // s 的长度
        for(int i = 0; i <= lenS - lenWord*numWords; i++){    // 第一层循环，从第一个字符开始移动，直到字符串 s 的剩余长度不足 words 中词的总长度时退出循环
            int count = numWords;   // words 中单词个数
            int j = i;              // 从 j 开始查找
            map<string,int> tmp(mapWords.begin(),mapWords.end()); 
            do{
                string strWord = s.substr(j,lenWord);  // 取长度为 lenWord 的词
                if(!tmp.count(strWord))                // 查找 strWord 是否在 words 中，不在，跳出循环
                    break;
                if(tmp[strWord] == 0) // 判断 strWord 出现的次数是否超过在 words 中出现的次数，若超过，则跳出循环
                    break;
                tmp[strWord]--; // 将 strWord 的出现次数减一
                count--;        // 将单词个数减一
                j += lenWord;   // 移动 j
            }while(count);      // count == 0 时结束循环，查找结束
            if(count == 0)
                res.push_back(i);
        }
        return res;
    }
};

int main(){
    string s = "foobarfoobar";
    string str[] = {"foo","bar"};
    sort(str,str+2);
    vector<string> words(str,str+sizeof(str)/sizeof(str[0]));
    Solution su;
    vector<int> vec = su.findSubstring(s,words);
    int i = 0;
    while(i < vec.size()){
        cout<<vec[i++]<<"\t";
    }
    return 0;
}