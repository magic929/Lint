#include<vector>
#include<iostream>
#include<climits>
#include<algorithm>

using namespace std;

class Solution{
public:
    int maxSubArray(vector<int> &nums){
        int cursum = 0, maxsum = INT_MIN;

        for(auto num : nums){
            if(cursum > 0){
                cursum += num;
            }
            else{
                cursum = num;
            }

            if(cursum > maxsum){
                maxsum = cursum;
            }
        }

        return maxsum;
    }
};

class Solution2{
public:
    int maxSubArray(vector<int> &nums){
        int maxsum = INT_MIN, minsum = 0, cursum = 0;
        for(auto num : nums){
            cursum += num;
            maxsum = max(maxsum, cursum - minsum);
            minsum = min(cursum, minsum);
        }
        return maxsum;
    }
};


int main(){
    vector<int> nums = {10, 2, -3, 4, -1, 2, 1, -5, 3};
    //Solution s = Solution();
    Solution2 s = Solution2();
    int result = s.maxSubArray(nums);
    cout << result;
}