#include<iostream>
#include<string>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        if(candidates.empty()) return vector<vector<int> >();
        sort(candidates.begin(),candidates.end());
        vector<vector<int> > res;
        vector<int> vec;
        combinationSum2(candidates,target,0,vec,res);
        return res;
    }
    void combinationSum2(vector<int>& candidates, int target, int l, vector<int>& vec, vector<vector<int> >& res){
        if(target < 0)
            return;
        if(target == 0){
            res.push_back(vec);
            return;
        }
        for(int i = l; i < candidates.size(); i++){
            if(i == l || candidates[i] != candidates[i-1]){
                vec.push_back(candidates[i]);
                combinationSum2(candidates,target-candidates[i],i+1,vec,res);
                vec.pop_back();
            }
            // while(candidates[i] == candidates[i+1]) ++i;
        }
    }
};

int main(){
    // int arr[] = {10, 1, 2, 7, 6, 1, 5};
    int arr[] = {1,1};
    int target = 2;
    // int target = 8;
    vector<int> vec(arr,arr+sizeof(arr)/4);
    vector<vector<int> > res;
    Solution su;
    res = su.combinationSum2(vec,target);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}