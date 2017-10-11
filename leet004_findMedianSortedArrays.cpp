class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size();
		int n = nums2.size();
		double median = 0;
		int pos = (m + n) / 2;
		int temp = 0, pre = 0, cur = 0;
		int i = 0, j = 0;
		for(; temp <= pos;) {
			pre = cur;
			if(i < m && j < n) {
				if(nums1[i] > nums2[j]) {
					cur = nums2[j];
					j++;
				} else {
					cur = nums1[i];
					i++;
				}
			}else{
                if(i < m){
                    cur = nums1[i];
                    i++;
                }else{
                    cur = nums2[j];
                    j++;
                }
            }
			temp++;
		}
        if((m + n) & 1){
            median = cur;
        }else{
            median = (cur + pre) * 1.0 / 2;
        }
        return median;
	}

    double findMedianSortedArraysNext(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size();
		int n = nums2.size();
		double median = 0;
		int pos = (m + n) / 2;
		int temp = 0, pre = 0, cur = 0;
		int i = 0, j = 0;
		while(temp <= pos) {
			pre = cur;
			if(i == m){
                cur = nums2[j++];
            }else if(j == n){
                cur = nums1[i++];
            }else if(nums1[i] > nums2[j]){
                cur = nums2[j++];
            }else{
                cur = nums1[i++];
            }
			temp++;
		}
        if((m + n) & 1){
            median = cur;
        }else{
            median = (cur + pre) * 1.0 / 2;
        }
        return median;
	}
    
};
