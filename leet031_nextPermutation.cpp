#include<iostream>
#include<string>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int i = len - 1;
                
        bool isSort = true;
        for(; i > 0; i--){
            if(nums[i] > nums[i-1]){
                isSort = false;
                if(i == len-1){
                    swap(nums[i],nums[i-1]);
                    break;
                }else{
                    int l = i, r = len-1;
                    while(nums[r] <= nums[i-1]) r--;
                    swap(nums[r],nums[i-1]);
                    // r = len - 1;
                    // while(l < r){
                        // swap(nums[l++],nums[r--]);
                    // } 
                    reverse(nums.begin()+i,nums.end());
                    break;
                }
            }
        }
        if(isSort){
            reverse(nums.begin(),nums.end());
        } 
        
/*         
        while(i && nums[i] <= nums[i-1]) --i;
        if(i == len - 1){
            swap(nums[i],nums[i-1]);
            return;
        }
        if(i == 0){
            reverse(nums.begin(),nums.end());
            return;
        }
        int r = len - 1;
        while(nums[r] <= nums[i-1]) r--;
        swap(nums[r],nums[i-1]);
        reverse(nums.begin()+i,nums.end());
        return; */
    }
};

int main(){
    Solution su;
    // int num[] = {1,2,3,4,5};
    // int num[] = {1,5,1};
    int num[] = {1,2};
    vector<int> nums(num,num+sizeof(num)/4);
    int j = 6;
    do{
        for(int i = 0; i < nums.size(); i++){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
        su.nextPermutation(nums);
    }while(j--);

    return 0;
}