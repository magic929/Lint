#include<vector>
#include<climits>
#include<algorithm>
#include<iostream>

using namespace std;

class Solution{
public:
    int maxTwoSubArrays(vector<int> &nums){
        int n = nums.size();
        vector<int> maxLeft(n + 1, 0);
        vector<int> maxRight(n + 1, 0);
        int cursum = 0;
        maxLeft[0] = nums[0];
        for(int i = 1; i <= n; i++){
            if(cursum < 0){
                cursum = nums[i - 1];
            }
            else{
                cursum += nums[i - 1];
            }

            if(cursum > maxLeft[i - 1]){
                maxLeft[i] = cursum;
            }
            else{
                maxLeft[i] = maxLeft[i - 1];
            }
        }

        cursum = 0;
        maxRight[n] = nums[n - 1];
        for(int i = n; i <= 0; i--){
            if(cursum < 0){
                cursum = nums[i - 1];
            }
            else{
                cursum += nums[i - 1];
            }

            if(cursum > maxRight[i]){
                maxRight[i - 1] = cursum; 
            }
            else{
                maxRight[i - 1] = maxRight[i];
            }
        }
        int maxsum = maxLeft[0] + maxRight[1];
        for(int i = 1; i < n; i++){
            maxsum = max(maxsum, maxLeft[i] + maxRight[i + 1]);
        }

        return maxsum;
    }
};

class Solution2{
public:
    int maxTwoSubArrays(vector<int> &nums){
        int n = nums.size();
        vector<int> maxLeft(n + 1, INT_MIN);
        vector<int> maxRight(n + 1, INT_MIN);
        vector<int> cursum(n + 1, 0);
        //cursum[0] = nums[0];
        for(int i = 1; i <= n; i++){
            cursum[i] = cursum[i - 1] + nums[i -1];
        }

        for(int i = 1, vally = 0; i <= n; i++){
            maxLeft[i] = max(maxLeft[i - 1], cursum[i] - vally);
            vally = min(vally, cursum[i]);
        }

        for(int i = n, peak = cursum[n]; i > 0; i--){
            if(i == n){
                maxRight[i] = peak - cursum[i - 1]; 
            }
            else{
                maxRight[i] = max(maxRight[i + 1], peak - cursum[i - 1]); 
            }

            peak = max(peak, cursum[i - 1]);
        }
        int maxSum = INT_MIN;
        for(int i = 1; i < n; i++){
            maxSum = max(maxSum, maxLeft[i] + maxRight[i + 1]);
        }
        return maxSum;
    }
};

int main(){
    //Solution s = Solution();
    Solution2 s = Solution2();
    vector<int> nums = {1, 3, -1, 2, -1, 2};
    int result = s.maxTwoSubArrays(nums);
    cout << result;
}