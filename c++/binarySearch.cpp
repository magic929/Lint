#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

// 二分法递归
// 1. 求出中间位置mid，mid的数值和target数值进行比较
// 2. 如果mid数值小，就代表target在右边，重复1
// 3. 如果mid数值大，就代表target在左边，重复1
// 4. 如果相等，则判断左边是否有相同的数值，如果有，在位置往左前移一个
// 5. 如果没有找到则返回 -1 
// 时间复杂度为 O(logn)

class Soultion{
    public:
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
};


int main(){
    // vector<int> nums = {1, 2, 3, 3, 4, 5, 10};
    // int target = 3;
    Soultion s = Soultion();
    string nums, target;
    getline(cin, nums, '\n');
    getline(cin, target, '\n');
    istringstream iss_nums(nums);
    istringstream iss_target(target);
    int itarget;
    vector<int> vnums;
    iss_target >> itarget;
    for(int n; iss_nums >> n; vnums.push_back(n)){;}
    int result = s.binarySearch(vnums, itarget);
    cout << result;
}