#include<iostream>
#include<vector>

using namespace std;

int recursive(vector<int> &nums, int target, int low, int high){
    int mid = (high + low) / 2;
    if(low >= high){
        return -1;
    }
    if(nums[mid] == target){
        while(mid >= 0 &&nums[--mid] == target);
        return ++mid;
    }
    else if(nums[mid] > target ){
        recursive(nums, target, low, mid);
    }
    else{
        recursive(nums, target, mid, high);
    }
}

int binarySearch(vector<int> &nums, int target){
    int low = 0;
    int high = nums.size();
    int result = recursive(nums, target, low, high);
    return result;    
}

int main(){
    vector<int> nums = {1, 2, 3, 3, 4, 5, 10};
    int target = 3;
    int result = binarySearch(nums, target);
    cout << result;
}