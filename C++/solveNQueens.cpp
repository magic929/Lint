#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<string> drawResult(vector<int> &cols, int n);
bool isValid(vector<int> &cols, int col);

void search(int n, vector<int> &cols, vector<vector<string>> &result){
    if(cols.size() == n){
        result.push_back(drawResult(cols, n));
    }

    for(int col = 0; col < n; col++){
        if(!isValid(cols, col)){
            continue;
        }

        cols.push_back(col);
        search(n, cols, result);
        cols.pop_back();
    }
}

vector<string> drawResult(vector<int> &cols, int n){
    vector<string> result;
    for(int i = 0; i < cols.size(); i++){
        string temp(n, '.');
        temp[cols[i]] = 'Q';
        result.push_back(temp);
    }

    return result;
}

bool isValid(vector<int> &cols, int col){
    int row = cols.size();
    
    for(int i = 0; i < row; i++){
        if(cols[i] == col){
            return false;
        }
        if(i - cols[i] == row- col){
            return false;
        }
        if(i + cols[i] == row + col){
            return false;
        }
    }

    return true;
}

vector<vector<string>> solveNQueens(int n){
    vector<vector<string>> result;
    if(n <= 0){
        return result;
    }

    vector<int> cols;
    search(n, cols, result);
    return result;
}

int main(){
    int n = 4;
    vector<vector<string>> result = solveNQueens(4);
    for(int i = 0; i < result.size(); i++){
        vector<string> tmp = result[i];
        for(int j = 0; j < tmp.size(); j++){
            cout << tmp[j] << "\n";
        }
        cout << "\n";
    }
}