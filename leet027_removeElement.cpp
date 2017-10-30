#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()) return 0;
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            while(nums[l] != val && l < nums.size()) ++l;
            while(nums[r] == val && r >= 0) --r;
            if(l < r)
                nums[l] = nums[r];
            else
                break;
            ++l;
            --r;
        }
        return r+1;
    }
};

int main(){

    return 0;
}