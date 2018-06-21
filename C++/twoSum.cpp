#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int> &numbers, int target){
        unordered_map<int, int> hash;
        vector<int> result;
        int n = numbers.size();
        for(int i = 0; i < n; i++){
            if(hash.find(target - numbers[i]) != hash.end()){
                result.push_back(hash[target - numbers[i]]);
                result.push_back(i);
                return result;
            }

            hash[numbers[i]] = i;
        }
    }
};

int main(){
    Solution s = Solution();
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = s.twoSum(numbers, target);
    for(auto r : result){
        cout << r << " ";
    }
}