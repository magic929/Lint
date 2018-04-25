#include <vector>
#include <iostream>

using namespace std;

class Solution{
    public:
        int searchMatrix(vector<vector<int>> &matrix, int target){
            int result = 0;
            if(matrix.size() == 0){
                return result;
            }
            int row = matrix.size();
            int col = matrix[0].size();
            int i = row - 1;
            int j = 0;

            while(i >= 0 && j < col){
                if(matrix[i][j] == target){
                    result++;
                }

                if(matrix[i][j] < target){
                    j++;
                }
                else{
                    i--;
                }
            }

            return result;
        }
};

int main(){
    vector<vector<int>> matrix = {{1,3,5,7}, {2,4,7,8}, {3,5,9,10}};
    int target = 3;
    Solution s = Solution();
    int result = s.searchMatrix(matrix, target);
    cout << result;
}