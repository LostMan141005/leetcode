#include<iostream>
#include<string>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > threeSumOld001(vector<int>& nums) {
		vector<vector<int> > res;
		if( nums.size() < 3) {
			return res;
		}

		/*
		        for(int i = 0; i < nums.size(); i++){
		            vector<int> vec(3);
		            vec[0] = nums[i];
		            for(int j = i + 1; j < nums.size(); j++){
		                vec[1] = nums[j];
		                bool flag = false;
		                for(int k = j + 1; k < nums.size(); k++){
		                    if(nums[i] + nums[j] + nums[k] == 0){
		                        vec[2] = nums[k];
		                        flag = true;
		                        break;
		                    }
		                }
		                if(flag){
		                    cout<<vec[0]<<vec[1]<<vec[2]<<endl;
		                    res.push_back(vec);
		                }
		            }

		        }
		 */
		sort(nums.begin(),nums.end());
		if(nums[0] > 0 || nums[nums.size()-1] < 0 ) {
			return res;
		}
		int l = 0;
		while(nums[l] <= 0) {
			int r = nums.size()-1;
			while(nums[r] >= 0) {
				int x = nums[l] + nums[r];
				int mid = -1;
				if(x < 0) {
					if(x >= 0 - nums[r]) {
						for(int i = r-1; i >= l && nums[i] > 0; i--) {
							if(0 - x == nums[i]) {
								mid = i;
								break;
							}
						}

					}
				} else {
					if(x <= 0 - nums[l]) {
						for(int i = l+1; i < r && nums[i] <= 0; i++) {
							if(0 - x == nums[i]) {
								mid = i;
								break;
							}
						}
					}
				}
				if(mid > -1) {
					vector<int> vec;
					vec.push_back(nums[l]);
					vec.push_back(nums[mid]);
					vec.push_back(nums[r]);
					res.push_back(vec);
					cout<<nums[l]<<nums[mid]<<nums[r]<<endl;
				}
				while(nums[r] == nums[r-1]) r -= 1;
				r--;
			}
			while(nums[l] == nums[l+1]) l += 1;
			l++;
		}

		return res;
	}

	vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(),nums.end());
		for(int k = 0; k < nums.size(); k++) {
			if(k > 0 && nums[k] == nums[k-1]) continue;
			else {
                int targetIndex = k;
				int i = targetIndex + 1;
				int j = nums.size()-1;
				while(i < j) {
					if(nums[targetIndex] + nums[i] + nums[j] < 0)   i++;
					else if(nums[targetIndex] + nums[i] + nums[j] > 0)   j--;
					else {
						vector<int> v;
						v.push_back(nums[targetIndex]);
						v.push_back(nums[i]);
						v.push_back(nums[j]);
						res.push_back(v);
						i++;
						j--;
						while(i < nums.size() && nums[i]==nums[i - 1]) i++;
						while(j >= 0 && nums[j] == nums[j + 1]) j--;
					}
				}
			}
		}
        return res;

	}
};



int main() {
	// int S[] = {-1, 0, 1, 2, -1, -4};
	// int S[] = {3,0,-2,-1,1,2};
	// int S[] = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
	// int S[] = {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
	// int S[] = {0,0,0};
	// int S[] = {-8,8,5,-2,-8,-9,-10,6,-3,-5,5,-6,-2,-6,5,-5,7,3,-4,0,-5,-2};
	int S[] = {-8,8,5,-2,-8,-9,-10,6,-3,-5,5,-6,-2,-6,5,-5,7,3,-4,0,-5,-2};
	sort(S,S+sizeof(S)/4);
	for(int i = 0; i < sizeof(S)/4; i++)
		cout<<S[i]<<" ";
	// int S[] = {-10,5,5};
	// int S[] = {1,-1,-1,0};
	vector<int> nums(S,S+sizeof(S)/4);
	Solution su;
	su.threeSum(nums);
	return 0;
}