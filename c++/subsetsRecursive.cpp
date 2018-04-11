#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void helper(vector<vector<int>> &result, vector<int> &nums, vector<int>tmp, int n){
    result.push_back(tmp);
    for(int i = n; i < nums.size(); i++){
        tmp.push_back(nums[i]);
        helper(result, nums, tmp, i + 1);
        tmp.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> &nums){
    vector<vector<int>> result;
    vector<int> tmp;
    if(nums.size() == 0){
        result.push_back(nums);
        return result;
    }
    sort(nums.begin(), nums.end());

    helper(result, nums, tmp, 0);
    return result;
}

int main(){
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = subsets(nums);
    for(int i = 0; i < result.size(); i++){
        vector<int> tmp = result[i];
        for(int j = 0; j < tmp.size(); j++){
            cout << tmp[j] << " ";
        }
        cout << "\n";
    }
}