#include<iostream>
#include<string>
#include<stdlib.h>
#include<vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.empty()) return 1;
        int len = nums.size()-1;
        for(int i = 0; i <= len; ++i){
            if(nums[i] > 0 && nums[i] <= len && nums[i] != nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
                if(nums[i] > 0 ) --i;
            }
            
        }
        int pos = 0;
        for(; pos < nums.size(); pos++){
            if(nums[pos] != pos+1)
                break;
        }
        return pos+1;
    }
};


int main(){
    // int arr[] = {1};
    // int arr[] = {3,4,-1,1};
    int arr[] = {-1,4,2,1,9,10};
    vector<int> vec(arr,arr+sizeof(arr)/4);
    Solution su;
    cout<<su.firstMissingPositive(vec)<<endl;    
    return 0;
}