#include<vector>
#include<algorithm>
#include<iostream>
#include<climits>

using namespace std;

class Solution{
public:
    int maxSubArray(vector<int> &nums, int k){
        int n = nums.size();
        vector<vector<int>>presum(n + 1, vector<int>(k + 1, INT_MIN / 2));
        vector<vector<int>>lastsum(n + 1, vector<int>(k + 1, INT_MIN / 2));

        presum[0][0] = 0;
        lastsum[0][0] = 0;

        for(int i = 1; i <= n; i++){
            presum[i][0] = 0;
            lastsum[i][0] = 0;

            for(int j = 1; j <= k; j++){
                presum[i][j] = max(presum[i - 1][j] + nums[i - 1], lastsum[i - 1][j - 1] + nums[i - 1]);
                lastsum[i][j] = max(lastsum[i - 1][j], presum[i][j]);
            }
        }

        return lastsum[n][k];
        
    }
};

int main(){
    Solution s = Solution();
    vector<int> nums = {-1, 4, -2, 3, -2, 3};
    int k = 2;
    int result = s.maxSubArray(nums, k);
    cout << result;
}