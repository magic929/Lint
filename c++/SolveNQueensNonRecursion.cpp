#include <vector>
#include <iostream>
#include <string>

using namespace std;

class N_Queens{
public:
    vector<vector<string>> results;

    vector<vector<string>> solveNQueens(int n){
        vector<int> cols;
        int i = 0, j = 0; 
        while(i < n){
            while(j < n){
                if(isVaild(cols, j)){
                    cols.push_back(j);
                    j = 0;
                    break;
                }
                else{
                    j++;
                }
            }

            if(cols.size() - 1 != i){
                if (i == 0){
                    break;
                }
                else{
                    i--;
                    j = cols.back() + 1;
                    cols.pop_back();
                    continue;
                }
                
            }

            if(cols.size() == n){
                results.push_back(drawNQ(cols));
                j = cols.back() + 1;
                cols.pop_back();
                continue;
            }
            i++;
        }

        return results;    
    }

    bool isVaild(vector<int> &cols, int col){
        int row = cols.size();
        for(int i = 0; i < row; i++){
            if(cols[i] == col){
                return false;
            }
            if(i - cols[i] == row - col){
                return false;
            }
            if(i + cols[i] == row + col){
                return false;
            }
        }

        return true;
    }

    vector<string> drawNQ(vector<int> cols){

        vector<string> result;
        for(int i = 0; i < cols.size(); i++){
            string tmp(cols.size(), '.');
            tmp[cols[i]] = 'Q';
            result.push_back(tmp);
        }
        return result;
    }   

};

int main(){
    N_Queens solution =  N_Queens();
    int n = 4;
    vector<vector<string>> result = solution.solveNQueens(n);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << "\n";
        }
        cout << "\n";
    }

}



