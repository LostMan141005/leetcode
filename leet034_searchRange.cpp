#include<iostream>
#include<string>
#include<stdlib.h>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1,-1};
        
        vector<int> res;
        int l = 0, r = nums.size()-1;
        int mid = 0;
        while(l <= r){
            mid = (l+r)/2;
            if(nums[mid] == target){
                break;
            }else if(nums[mid] <  target){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        if(l > r){
            res.push_back(-1);
            res.push_back(-1);
        }else{
            int ll = mid, rr = mid;
            while(nums[ll] == target && ll > -1 ) --ll;
            while(nums[rr] == target && rr < nums.size()) ++rr;
            ++ll;
            --rr;
            res.push_back(ll);
            res.push_back(rr);
        }
        return res;
    }
};


int main(){
    int arr[] = {8};
    int target = 8;
    vector<int> vec(arr,arr+sizeof(arr)/sizeof(int));
    Solution su;
    vector<int> res;
    res = su.searchRange(vec,target);
    cout<<res[0]<<" "<<res[1]<<endl;

    return 0;
}