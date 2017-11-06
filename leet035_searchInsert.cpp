#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int pos = 0;
        while(pos < nums.size() && nums[pos] < target){
            ++pos;
        }
        return pos;
    }
};

int main(){

    return 0;
}