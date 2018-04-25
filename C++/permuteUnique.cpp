#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

 vector<vector<int>> permuteUnique(vector<int> &nums) {
        // write your code here
        // the same of next_permutation
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int length = nums.size();
        result.push_back(nums);
        if(length == 0 || length == 1){
            return result;
        }
        int i = nums.size() - 2;
        int j = nums.size() - 1;

        for (; i >= 0; i--, j--){
            if(nums[i] < nums[j]){
                 int min = -1;
            for(int t = nums.size() - 1; t > i; t--){
                if(nums[t] > nums[i] && ( min == -1 || nums[t] < nums[min])){
                    min = t;
                }
            }
            swap(nums[i], nums[min]);
            reverse(nums.begin() + i + 1, nums.end());
            result.push_back(nums);
            i = nums.size() - 1;
            j = nums.size() - 0;
          }
        }
        
        return result;
    }

int main(){
    vector<int> nums = {1, 2, 2};
    vector<vector<int>>result = permuteUnique(nums);
    for(int i = 0; i < result.size(); i++){
        vector<int> tmp = result[i];
        for(int j = 0; j < tmp.size(); j++){
            cout << tmp[j] << " ";
        }
        cout << "\n";
    }
}