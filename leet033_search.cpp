#include<iostream>
#include<string>
#include<stdlib.h>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        int len = nums.size();
        int l = 0, r = len - 1, mid = len - 1;
        while(l < r && nums[mid] < nums[l]) --mid;
    
        if(target >= nums[l]){
            r = mid;
        }else if(mid != r){
            l = mid+1;
        }
        return binarySearch(nums,l,r,target);
    }
    int binarySearch(vector<int>& nums, int l, int r, int target){
        while(l <= r){
            int mid = (l+r)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
    
/*       int search(vector<int>& nums, int target) {
        if(nums.empty())return -1;
        
        int low  = 0;
        int high = nums.size() - 1;
        
        while(low < high){
            int mid = (low + high)/2;
            
            if(nums[mid] == target)return mid;
            
            if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target < nums[mid]){
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }
            }else{
                if(nums[mid] < target && target <= nums[high]){
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }
            }
        }
        return (nums[low] == target) ? low : -1;
    } */
    
};

int main(){

    return 0;
}