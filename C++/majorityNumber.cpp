#include<vector>
#include<iostream>

using namespace std;

class Solution{
public:
    int majortyNumber(vector<int> &nums){
        int tmp, count = 0;
        for(auto num : nums){
            if (count == 0){
                tmp = num;
                count++;
            }
            else{
                count = tmp == num ? count++ : count--;
            }
        }

        return tmp;
    }
};

int main(){
    Solution s = Solution();
    vector<int> nums = {1, 1, 1, 1, 2, 2, 2};
    int result = s.majortyNumber(nums);
    cout << result;
}