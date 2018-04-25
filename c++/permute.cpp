#include<iostream>
#include<vector>

using namespace std;

void helper(vector<vector<int>> &result, vector<int> nums, int n){
    if(n == 0){
        result.push_back(nums);
    }

    for(int i = 0; i <= n; i++){
        swap(nums[i], nums[n]);
        helper(result, nums, n - 1);
        swap(nums[i], nums[n]);
    }
}

// 回溯算法: 一个数组可以由固定一个数，在各个位置的情况
// 1. 判断数组长度为0 则返回空数组
// 2. 从数组开头开始，跟数组结尾交换。递归直到到头。进入容器
// 3，回溯到上一个情况。重复2
// 时间复杂度为：O(n!) 
vector<vector<int>> permute(vector<int> &nums){
    vector<vector<int>> result;
    int n = nums.size() - 1;
    if(n == -1){
        result.push_back(vector<int>());
        return result;
    }

    helper(result, nums, n);
    return result;
}

int main(){
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = permute(nums);
    for(int i = 0; i < result.size(); i++){
        vector<int> tmp = result[i];
        for(int j = 0; j < tmp.size(); j++){
            cout << tmp[j];
        }
        cout << "\n";
    }
}