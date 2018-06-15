#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    vector<int> previousPermuation(vector<int> &nums){
        int n = nums.size();
        int i = n - 1;
        while(i > 0 && nums[i - 1] < nums[i]){
            i--;
        }
        
        if(i == 0){
           reverse(nums.begin(), nums.end());
        }
        else{
            int j = i;
            while(j < n && nums[j] < nums[i - 1]){
                j++;
            }
            j--;

            int tmp = nums[j];
            nums[j] = nums[i - 1];
            nums[i - 1] = tmp;

            reverse(nums.begin() + i, nums.end());
        }

        return nums;

    }
};

int main(){
    Solution s = Solution();
    //vector<int> nums = {1, 3, 2, 3};
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = s.previousPermuation(nums);
    for(auto r : result){
        cout << r << " ";
    }
}