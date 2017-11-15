#include<iostream>
#include<string>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        if(candidates.empty()) return vector<vector<int> >();
        sort(candidates.begin(),candidates.end());
        int l = 0, r = candidates.size()-1;
        
        vector<vector<int> > res;
        vector<int> vec;
        combinationSum(candidates,target,l,vec,res);
        return res;
        
        // return combinationSum(candidates, l, r, target); 
    }
    vector<vector<int> > combinationSum(vector<int>& candidates, int l, int r, int target){
        if(candidates.empty()) return vector<vector<int> >();
        vector<vector<int> > res;
        while(candidates[r] > target) --r;
        if(target == candidates[r]){
            vector<int> v;
            v.push_back(target);
            res.push_back(v);
            while(l <= r && candidates[r] == target) --r;
        }
        while(l <= r){
            vector<vector<int> > vec;
            int tmp = target - candidates[l];
            
            while(l <= r && tmp < candidates[r]) --r;
            if(l <= r){
                vec = combinationSum(candidates, l, r, tmp);
                for(int i = 0; i < vec.size(); i++){
                    vec[i].push_back(candidates[l]);
                    res.push_back(vec[i]);
                }
            }
            ++l;
        }
        return res;
    }
    
    void combinationSum(vector<int>& candidates, int target, int l, vector<int>& vec, vector<vector<int> >& res){
        if(target < 0){
            return;
        }
        if(target == 0){
            res.push_back(vec);
            return;
        }
        for(int i = l; i < candidates.size(); i++){
            vec.push_back(candidates[i]);
            combinationSum(candidates,target-candidates[i],i,vec,res);
            vec.pop_back();
        }
    }
};

int main(){
    // int arr[] = {1,2,3,6,7};
    int arr[] = {1,2};
    // int target = 7;
    int target = 4;
    vector<int> vec(arr,arr+sizeof(arr)/4);
    Solution su;
    vector<vector<int> > res;
    res = su.combinationSum(vec,target);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}