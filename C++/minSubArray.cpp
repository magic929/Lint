#include<vector>
#include<climits>
#include<algorithm>
#include<iostream>

using namespace std;

class Soultion {
public:
    int minSubArray(vector<int> &nums){
        int sum = 0, result = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(sum <= 0){
                sum += nums[i];
            }
            else{
                sum = nums[i];
            }

            result = min(sum, result);
        }

        return result;
    }
};

int main(){
    Soultion s = Soultion();
    vector<int> nums = {1, -1, -2, 1};
    int result = s.minSubArray(nums);
    cout << result;
}