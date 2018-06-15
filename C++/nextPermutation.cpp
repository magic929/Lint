#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    vector<int> nextPermutation(vector<int> &nums){
        int n = nums.size();
        int i = n - 1;

        while(i > 0 && nums[i - 1] > nums[i]){
            i--;
        }

        if( i == 0){
            reverse(nums.begin(), nums.end());
            return nums;
        }

        int j = i;
        
        while(j < n && nums[i] < nums[j]){
            j++;
        }

        swap(nums[i - 1], nums[j]);
        reverse(nums.begin() + i, nums.end());

        return nums;
    }
};

int main(){
    Solution s = Solution();
    //vector<int> nums = {1, 3, 2 ,3};
    vector<int> nums = {4,3,2,1};
    vector<int> result = s.nextPermutation(nums);
    for(auto r : result){
        cout << r << " ";
    }
}