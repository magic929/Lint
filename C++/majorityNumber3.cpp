#include<vector>
#include<iostream>

using namespace std;

struct Candidate{
    int val;
    int count;
    Candidate(int x = 0, int y = 0): val(x), count(y){}
};

class Solution{
public:
    int majorityNumber(vector<int> &nums, int k){
        int n = nums.size();
        vector<Candidate> key(k - 1, Candidate());
        int j;
        for(int i = 0; i < n; i++){
            for(j = 0; j < k - 1; j++){
                if(key[j].val == nums[i]){
                    key[j].count ++;
                    break;
                }
            }

            if(j == k - 1){
                for(j = 0; j < k - 1; j++){
                    if(key[j].count == 0){
                        key[j].val = nums[i];
                        break;
                    }
                }

                if(j == k - 1){
                    for(j = 0; j < k - 1; j++){
                        key[j].count --;
                    }
                }
            }
        }

        for(int i = 0; i < k - 1; i++){
            key[i].count = 0;
        }
        for(int i = 0; i < n; i++){
            for(j = 0; j < k - 1; j++){
                if(key[j].val == nums[i]){
                    key[j].count ++ ;
                }
                if(key[j].count > n / k){
                    return key[j].val;
                }               
            }
        }
    }
};

int main(){
    Solution s = Solution();
    vector<int> nums = {3,1,2,3,2,3,3,4,4,4};
    int k = 3;
    int result = s.majorityNumber(nums, k);
    cout << result;
}