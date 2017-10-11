#include<iostream>
#include<string>
#include<stdlib.h>
#include<vector>
using namespace std;

class Solution {
public:

    int maxAreaOld001(vector<int>& height) {
        int area = 0;
        for(int i = 0; i < height.size()-1; i++){
            for(int j = i+1; j < height.size(); j++){
                int mi = min(height[i],height[j]);
                area = max(mi*(j-i),area);
            }
        }
        return area;
    }
    
    int maxArea(vector<int>& height) {
        int area = 0;
        int l = 0, r = height.size()-1;
        while(l < r && l >= 0 && r < height.size()){
            area = max(area,min(height[l],height[r])*(r-l));
            if(height[l] > height[r]){
                r--;
            }else{
                l++;
            }
        }
        return area;
    }
};



int main(){
    int a[] = {3, 4, 8, 5, 7, 6};
    vector<int> vec(a,a+6);
    Solution su;
    cout<<su.maxArea(vec);
    return 0;
}