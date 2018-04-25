#include<vector>
#include<iostream>

using namespace std;

int partitionArray(vector<int> &nums, int k){
    int low = 0;
    int high = nums.size() - 1;
    int pos;

    if(nums.size() == 0){
        return 0;
    }

    while(low < high){
        while(nums[low] < k){
            low++;
        }
        while(nums[high] >= k){
            high--;
        }

        if(low < high){
            swap(nums[low], nums[high]);
            pos = low + 1;
        }
        else{
            pos = low;
        }
    }

    return pos;
}

int main(){
    vector<int> nums = {3, 2, 2, 1};
    int k = 2;
    int result = partitionArray(nums, k);
    cout << result;
}