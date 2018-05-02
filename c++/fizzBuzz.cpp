#include<string>
#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

    // 直接字符串构造（可用一个if语句）
    // 1. 先判断是否为3， 如果是则返回fizz
    // 2. 再判断是否为15， 如果是则返回空格
    // 3. 最后判断是否为5， 如果是则返回buzz
    // 注： 顺序很重要
    // 时间复杂度为：O(n)
class Solution{
public:
    string helper(int mod, string w){
        return mod == 0? w : "";
    }
   
    vector<string> fizzBuzz(int n){
        vector<string> result;
        for(int i = 1 ; i <= n; i++){
            string tmp = helper(i % 3, "fizz") + helper(i % 15, " ") + helper(i % 5, "buzz");
            if(tmp == ""){
                result.push_back(to_string(i));
            }
            else{
                result.push_back(tmp);
            }
        }

        return result;
    }

};


int main(){
    Solution s = Solution();
    string sn;
    getline(cin, sn);
    stringstream ssn(sn);
    int n;
    ssn >> n;
    vector<string> result = s.fizzBuzz(n);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << ",";
    }
}