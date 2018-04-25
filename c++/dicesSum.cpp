#include<iostream>
#include<vector>
#include<iostream>
#include<sstream>
#include<iomanip>

using namespace std;

/*
    n个骰子正面相加点数的概率-数学规律
    1. n个骰子的最大点数是n*6,最小点数是n， 用一个vector<vector<double>>来存储每个筛子对应的数值概率
    2. 初始化只有1个时候的概率，其位 1/6
    3. 开始从第2个骰子开始遍历，加上此前该数值的概率，最后除以6直到遍历到最后一个骰子
    4. 最后一层的概率就是所有骰子加起来综合的概率
*/
class Soultion{
    public:
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
            for(int i = n; i <= n*6; i++){
                results.push_back(make_pair(i, f[n][i]));
            }

            return results;
        }   
};   


int main(){
    Soultion s = Soultion();
    // int n = 2;
    string sn;
    getline(cin, sn);
    stringstream ssn(sn);
    int n;
    ssn >> n;
    vector<pair<int, double>> results = s.dicesSum(n);
    for(int i = 0; i < results.size(); i++){
        pair<int, double> tmp = results[i];
        cout << tmp.first <<": " << setiosflags(ios::fixed) << setprecision(2) << tmp.second << "\n";
    }
}