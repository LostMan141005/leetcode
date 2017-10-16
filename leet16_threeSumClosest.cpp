#include<iostream>
#include<string>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;

class SolutionOld {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int res = 0, sub;
		sort(nums.begin(),nums.end());
		res = nums[0] + nums[1] + nums[nums.size()-1];
		sub = res - target;

		for(int i = 0; i < nums.size() - 2; i++) {
			int l = i + 1;
			int r = nums.size() - 1;
			while(l < r) {
				int resTemp = nums[i] + nums[l] + nums[r];
				int temp = resTemp - target;
				// int subTemp = sub > 0? sub:0-sub;
                
                if(temp == 0) return resTemp;
                if(temp < 0) l++;
                else r--;
                if(abs(sub) > abs(temp)){
                    sub = temp;
                    res = resTemp;
                }
                
                
/*                 
				if(temp > 0) {
					if(temp <= subTemp) {
						sub = temp;
						res = resTemp;
					}
					r--;
				} else if(temp == 0) {
					res = resTemp;
					i = nums.size();
					break;
				} else {
					temp = 0 - temp;
					if(temp <= subTemp) {
						res = resTemp;
						sub = 0 - temp;
					}
					l++;
				}
                 */
                
			}
		}
		return res;
	}
};

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		/*
		1. Simple Solution
		2. https://discuss.leetcode.com/topic/17215/c-solution-o-n-2-using-sort/2
		3. Sorting has to be done before. Otherwise, solution will be O(n^3)
		4. Solved in ARRAY
		5. Few Corner Cases as well.


		*/
		if(nums.size() < 3) return 0;
		int j, k;
		int sum;
		int closest = nums[0] + nums[1] + nums[2];
		sort(nums.begin(), nums.end());
		int i = 0;
		for(i = 0; i < nums.size()-2; i++) {
			j = i + 1;
			k = nums.size()-1;
			while(j < k ) {
				sum = nums[i] + nums[j] + nums[k];
				if(sum == target) return sum;
                
                // 会连续执行两遍
/* 				if(abs(target - sum) < abs(target - closest)) closest = sum; 
				else if(sum > target) k--;
				else if(sum < target) j++; */
                
                if(sum > target) k--;
                else j++;
                if(abs(target - sum) < abs(target - closest)) closest = sum; 
			}
		}
		return closest;
	}
};

int main() {
	Solution su;
	// int arr[] = {-1,2,1,-4};
	// int arr[] = {0,0,0};
	// int arr[] = {1,1,1,0};
	int arr[] = {1,2,4,8,16,32,64,128};
	vector<int> vec(arr,arr+sizeof(arr)/sizeof(int));
	cout<<su.threeSumClosest(vec,82)<<endl;
	return 0;
}