#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void helper(vector<vector<int>> &result, vector<int> tmp, vector<int> &nums, int n){
    if(find(result.begin(), result.end(), tmp) == result.end()){
        result.push_back(tmp);
    }

    for(int i = n; i < nums.size(); i++){
        tmp.push_back(nums[i]);
        helper(result, tmp, nums, i + 1);
        tmp.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums){
    vector<vector<int>> result;
    vector<int> tmp;
    sort(nums.begin(), nums.end());
    
    helper(result, tmp, nums, 0);

    return result;
}

int main(){
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> result = subsetsWithDup(nums);
    for(int i = 0; i < result.size(); i++){
        vector<int> tmp = result[i];
        for(int j = 0; j < tmp.size(); j++){
            cout << tmp[j] << " ";
        }
        cout << "\n";
    }
}