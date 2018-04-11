#include<vector>

using namespace std;

/*
  快排思想
  1. 先设定一个基准值 nums[0] 
  2. 先从左边开始找到一个小于基准值的值
  3. 再从右边开始找到一个大于基准值的值
  4. 交换这两个值
  5. 重复2-4, 直到左右两边碰头, 交换第基准值和右边所在的数值. (此时该值的位置就是他的第几大的位置)
  6. 直到此位置是K的位置时结束
  时间复杂度：O(n)

*/
int findKthLargest(vector<int>& nums, int k){
    int high = nums.size();
    int low = 0;

    while(low < high){
        int i = low;
        int j = high - 1;
        int pivot = nums[low];
        while(i <= j){
            while(i <= j && nums[i] >= pivot){
                i ++ ;
            }
            while(i <= j && nums[j] <= pivot){
                j--;
            }
            if(i < j){
                swap(nums[i++], nums[j--]);
            }
        }
            swap(nums[low], nums[j]);
            if(j == k -1){
                return nums[j];
            }
            else if(j < k - 1){
                low = j + 1;
            }
            else{
                high = j;
            }
    }
}