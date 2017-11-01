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
            mid = (l+r)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
};

int main(){

    return 0;
}