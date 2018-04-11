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

vector<vector<int>> nonRecPermute(vector<int> &nums){
     vector<vector<int>> result;
        int n = nums.size() - 1;
        int max = n;
        if(max < 0){
            result.push_back(nums);
            return result;
        }
        int i = 0;
        while(i <= max){
            swap(nums[i], nums[n]);
            while((--n) > 0){
                swap(nums[i], nums[n]);
            }
            result.push_back(nums);
            swap(nums[i], nums[n]);
            i++;
        }
        
        return result;
}

int main(){
    vector<int> nums = {1, 2, 3};
    //vector<vector<int>> result = permute(nums);
    vector<vector<int>> result = nonRecPermute(nums);
    for(int i = 0; i < result.size(); i++){
        vector<int> tmp = result[i];
        for(int j = 0; j < tmp.size(); j++){
            cout << tmp[j];
        }
        cout << "\n";
    }
}