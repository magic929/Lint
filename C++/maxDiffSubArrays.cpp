#include<vector>
#include<algorithm>
#include<climits>
#include<iostream>

using namespace std;

class Solution{
public:
    int maxDiffSubArrays(vector<int> &nums){
        int n = nums.size();
        vector<int> left_max(n), left_min(n), right_max(n), right_min(n);
        for(int i = 0, peek = INT_MIN, cur = 0; i < n; i++){
            cur += nums[i];
            peek = max(cur, peek);
            left_max[i] = peek;
            if (cur < 0){
                cur = 0;
            }
        }

        for(int i = n - 1, peek = INT_MIN, cur = 0; i >= 0; i--){
            cur += nums[i];
            peek = max(cur, peek);
            right_max[i] = peek;
            if(cur < 0){
                cur = 0;
            }
        }

        for(int i = 0, peek = INT_MAX, cur = 0; i < n; i++){
            cur += nums[i];
            peek = min(cur, peek);
            left_min[i] = peek;
            if(cur > 0){
                cur = 0;
            }
        }

        for(int i = n - 1, peek = INT_MAX, cur = 0; i >= 0; i--){
            cur += nums[i];
            peek = min(cur, peek);
            right_min[i] = peek;
            if(cur > 0){
                cur = 0;
            }
        }

        int max1 = INT_MIN, max2 = INT_MIN;
        for(int i = 0, cur = 0; i < n; i++){
            max1 = max(max1, left_max[i] - right_min[n - i - 1]);
            max2 = max(max2, right_max[i] - left_min[n - 1 - i]);
        }
        
        return max(max1, max2);
    }
};

int main(){
    Solution s = Solution();
    vector<int> nums = {1, 2, -3, 1};
    int result = s.maxDiffSubArrays(nums);
    cout << result;
}

