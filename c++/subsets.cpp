#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

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