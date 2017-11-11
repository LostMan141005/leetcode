#include<iostream>
#include<string>
#include<stdlib.h>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;


class Solution{
    public:
 /*    vector<int> twoSum(vector<int>& nums, int target){
       int flag = 0;
        int i,j;
        vector<int> res;
        for(i=0; i < nums.size(); i++){
            for(j=i+1; j < nums.size(); j++){
                if(target == nums[i]+nums[j]){
                    flag = 1;
                    goto end;
                }
            }
        }
        end:
        if(flag){
            res.push_back(i);
            res.push_back(j);  
        }
        return res;
    } */
    vector<vector<int> > twoSum(vector<int>& nums, int target){
        if(nums.size() < 2) return vector<vector<int> >();
        vector<vector<int> > res;
        int l = 0, r = nums.size()-1;
        sort(nums.begin(),nums.end());
        while(l < r){
            if(nums[l] + nums[r] == target){
                vector<int> v;
                v.push_back(nums[l]);
                v.push_back(nums[r]);
                res.push_back(v);
                // cout<<nums[l]<<" "<<nums[r]<<endl;
                
                while(nums[++l] == nums[l-1]) ++l;
                while(nums[++r] == nums[r-1]) --r;
            }else if(nums[l] + nums[r] > target){
                --r;
            }else{
                ++l;
            }
        }
        return res;
    }
    /* vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.size() < 2) return {};
        vector<int> res;
        map<int,int> mm;
        for(int i = 0; i < nums.size(); i++){
            if(mm.find(target - nums[i]) != mm.end()){
                res.push_back(i);
                res.push_back(mm[target - nums[i]]);
                return res;
            }
            mm[nums[i]] = i;
        }
        return res;
    } */
};

int main(){
    int arr[] = {3,3,1,4,5,7,-1,2,2,7,5,3};
    int target = 6;
    vector<int> vec(arr,arr+sizeof(arr)/4);
    Solution su;
    su.twoSum(vec,target);

    return 0;
}