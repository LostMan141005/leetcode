#include<iostream>
#include<string>
#include<stdlib.h>
#include<vector>
using namespace std;


class Solution{
    public:
    vector<int> twoSum(vector<int>& nums, int target){
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
    }
};

int main(){

    return 0;
}