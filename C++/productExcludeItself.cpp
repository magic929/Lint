#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    vector<long long> productExcludeItself(vector<int> &nums){
        int n = nums.size();
        vector<long long> left(n, 1);
        vector<long long> right(n, 1);
        vector<long long> result;

        for(int i = 1; i < n; i++){
            left[i] = left[i - 1] * nums[i - 1];
        }

        for(int i = n - 2; i >= 0; i--){
            right[i] = right[i + 1] * nums[i + 1];
        }

        for(int i = 0; i < n; i++){
            result.push_back(left[i] * right[i]);
        }

        return result;
    }
};

int main(){
    Solution s = Solution();
    vector<int> nums = {1, 2, 3};
    vector<long long> result = s.productExcludeItself(nums);
    for(auto r : result){
        cout << r << " ";
    }
}