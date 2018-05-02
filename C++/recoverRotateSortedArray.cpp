#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution{
    public:
        void recoverRotatedSortedArray(vector<int> &nums){
            int i = 1;
            for(; i < nums.size(); i++){
                if(nums[i - 1] > nums[i]){
                    break;
                }
            }
            int j = 0;
            while(j < i){
                int tmp = nums[0];
                nums.erase(nums.begin());
                nums.push_back(tmp);
                j++;
            }
        }
};

class Solution2{
    public:
        void recoverRotatedSortedArray(vector<int> &nums){
            int i = 1;
            for(; i < nums.size(); i++){
                if(nums[i - 1] > nums[i]){
                    break;
                }
            }
            
            reverse(nums.begin(), nums.begin() + i);
            reverse(nums.begin() + i , nums.end());
            reverse(nums.begin(), nums.end());
        }
};

int main(){
    // Solution s = Solution();
    Solution2 s = Solution2();
    vector<int> nums = {4, 5, 1, 2, 3};
    s.recoverRotatedSortedArray(nums);
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
}