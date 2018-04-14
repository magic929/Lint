#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 非递归方法，所有子集都是从前一个子集当中加上新的数值
// 1. 先进性排序(题目要求必须非降序)
// 2. 在result里压入一个空集
// 3. 遍历result，把新数值依次压入上一次的结果中，在压入result
// 4. 直到所有数字全部填入完
// 时间复杂度：O(n^2)
vector<vector<int>> subsets(vector<int> &nums){
    vector<vector<int>> result;
    vector<int> tmp;
    sort(nums.begin(), nums.end());
    result.push_back(tmp);
    for(int i = 0; i < nums.size(); i++){
        int length = result.size();
        for(int j = 0; j < length; j++){
            tmp = result[j];
            tmp.push_back(nums[i]);
            result.push_back(tmp);
        }
    }

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