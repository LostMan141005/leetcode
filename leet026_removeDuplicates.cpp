#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int pos = 1, i = 1;
        while(i < nums.size()){
            while(i < nums.size() && nums[i-1] == nums[i]) ++i;
            if(i >= nums.size()) break;
            nums[pos++] = nums[i++];
        }
        return pos;
    }
};

int main(){

    return 0;
}