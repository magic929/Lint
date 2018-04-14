#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> permute(vector<int> &nums){
    vector<vector<int>> result;
    // 先从小到大排序
    sort(nums.begin(), nums.end());
    result.push_back(nums);
    // 字典法
    // 123456的下一个是123465
    //1. 从后开始找升序的一堆数字i,j
    //2. 从后找大于i的最小数字min
    //3. 交换i和min
    //4. 把i之后的数组反转
    while(next_permutation(nums.begin(), nums.end())){
        result.push_back(nums);
    }

    return result;
}

int main(){
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = permute(nums);
    for(int i = 0; i < result.size(); i++){
        vector<int> tmp = result[i];
        for(int j = 0; j < tmp.size(); j++){
            cout << tmp[j] << " ";
        }
        cout << "\n";
    }
}