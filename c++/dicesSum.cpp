#include<iostream>
#include<vector>

using namespace std;

vector<pair<int, double>> dicesSum(int n){
    vector<pair<int, double>> results;
    vector<vector<double>> f(n + 1, vector<double>(6 * n + 1));

    for(int i = 1; i <= 6; i++){
        f[1][i] = 1.0 / 6;
    }

    for(int i = 2; i <= n; i++){
        for(int j = i; j <= n*6; j++){
            for(int k = 1; k <= 6; k++){
                if(j > k){
                    f[i][j] += f[i -1][j - k];
                }
            }
            f[i][j] /= 6;
        }
    }
    for(int i = 1; i <= n*6; i++){
        results.push_back(make_pair(i, f[n][i]));
    }

    return results;
}

int main(){
    int n = 2;
    vector<pair<int, double>> results = dicesSum(n);
    for(int i = 0; i < results.size(); i++){
        pair<int, double> tmp = results[i];
        cout << tmp.first <<": " << tmp.second << "\n";
    }
}