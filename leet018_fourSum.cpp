#include<iostream>
#include<string>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > fourSum(vector<int>& nums, int target) {
		if(nums.size() < 4) return vector<vector<int> >();
		vector<vector<int> > res;
		sort(nums.begin(),nums.end());
		int len = nums.size();
		for(int i = 0; i < len; i++) {
			if(i > 0 && nums[i] == nums[i - 1]) continue;
			int a = nums[i];
			int tarT = target - a;
			for(int j = i + 1; j < len; j++) {
				if(j > i+1 && nums[j] == nums[j-1]) continue;
				int b = nums[j];
				int l = j + 1;
				int r = len - 1;
				while(l < r) {
					if(b + nums[l] + nums[r] == tarT) {
						vector<int> vec;
						vec.push_back(a);
						vec.push_back(b);
						vec.push_back(nums[l]);
						vec.push_back(nums[r]);
						res.push_back(vec);
						l++;
						r--;
						while(l < nums.size() && nums[l]==nums[l - 1]) l++;
						while(r >= 0 && nums[r] == nums[r + 1]) r--;
					} else if(b + nums[l] + nums[r] > tarT) {
						r--;
					} else {
						l++;
					}
				}
				// while(nums[j] == nums[j+1] && j < len) ++j;
			}
		}
		return res;
	}
};


/* #include<set> // set 不允许两个元素有相同的值
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4){
            return vector<vector<int>>();
        }
        sort(nums.begin(),nums.end());
        set<vector<int>> res;
        int len = nums.size();
        for(int i = 0; i < len; i++ )
            for(int j = i+1; j < len; j++){
                int k = j+1;
                int l = len -1;
                while(k<l){
                    int sum = nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum== target){
                        res.insert({nums[i],nums[j],nums[k],nums[l]});
                        while(k+1<l&&nums[k]==nums[k+1]) k++;
                        while(k<l-1&&nums[l]==nums[l-1]) l--;
                    }
                    if(sum>target){ l--;}
                    else {k++;}
                }

            }
        return vector<vector<int>>(res.begin(),res.end());
    }
}; */

/* class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
		int size = nums.size();
		if(size<4) return result;
		sort(nums.begin(), nums.end());
		for(int i = 0, iend = size-3; i < iend; ++i) {
			if(i >0 && nums[i] == nums[i-1]) continue;
			if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
			if(nums[i]+nums[size-3]+nums[size-2]+nums[size-1]<target) continue;

			for(int jstart = i+1, j = jstart, jend = size - 2; j < jend; ++j) {
				if(j > jstart && nums[j] == nums[j-1]) continue;
				int twoTarget = target - nums[i] - nums[j];
				if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
				if(nums[i]+nums[j]+nums[size-2]+nums[size-1]<target) continue;

				int start = j + 1;
				int end = size - 1;
				while (start<end) {
					int sum = nums[start] + nums[end];
					if( sum < twoTarget) {
						++start;
					} else if ( sum > twoTarget) {
						--end;
					} else {
						result.push_back( {nums[i], nums[j], nums[start], nums[end]});
						while( ++start < end && nums[start] == nums[start-1]);
						while( start < --end && nums[end] == nums[end+1]);
					}
				}
			}
		}
		return result;
	}
}; */

int main() {
	Solution su;
	// int arr[] = {1, 0, -1, 0, -2, 2}, target = 0;
	// int arr[] = {-3,-2,-1,0,0,1,2,3}, target = 0;
	// int arr[] = {-1,-5,-5,-3,2,5,0,4}, target = -7;
	int arr[] = {1,4,-2,-8,6,1,7,-8,-4,-5,-9,0,4,-9,3,5,-8,1,9}, target = -17;
	// int arr[] = {0,0,0,0}, target = 0;
	// int arr[] = {-1,0,1,2,-1,-4}, target = -1;
	vector<int> vec(arr,arr + sizeof(arr)/4);
	vector<vector<int> > res = su.fourSum(vec,target);
	for(int i = 0; i < res.size(); i++) {
		for(int j = 0; j < 4; j++) {
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}


	return 0;
}