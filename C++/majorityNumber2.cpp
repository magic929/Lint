#include<vector>
#include<iostream>

using namespace std;

class Solution{
public:
    int majorityNumer(vector<int> &nums){
        int n = nums.size();
        int a, ac = 0, b, bc = 0;
        for(int i = 0; i < n; i++){

            if (ac == 0)
            {
                a = nums[i];
                ac++;
            }

            else if (bc == 0)
            {
                b = nums[i];
                bc++;
            }

            else if (a == nums[i])
            {
                ac++;
            }
            else if (b == nums[i])
            {
                bc++;
            }
            else
            {
                ac--;
                bc--;
            }
        }
        ac = 0, bc = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == a){
                ac++;
            }
            else if (nums[i] == b){
                bc++;
            }
        }

        int result = ac > bc ? a : b;
        return result;
    }
};

int main(){
    Solution s = Solution();
    vector<int> nums = {3,1,2,3,2,3,3,4,4,4};
    int result = s.majorityNumer(nums);
    cout << result;   
}