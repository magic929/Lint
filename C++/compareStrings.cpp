#include<iostream>
#include<string>


using namespace std;

/*
 题目：比较A是否包含B中所有字符
 1. 类似于hash表，把A每个字符串计数
 2. 遍历B，如果有相同字符则计数减一
 3. 其中当字符计数小于0的时候，则判断为false
*/

class Solution{
public:
    bool compareStrings(string &A, string &B){
        int count[26];
        for(int i = 0; i < 26; i++){
            count[i] = 0;
        }
        //1. 类似于hash表，把A每个字符串基数
        for(int i = 0; i < A.length(); i++){
            count[A[i] - 'A']++;
        }
        //2. 遍历B，如果有相同字符则计数减一
        //3. 其中当字符计数小于0的时候，则判断为false
        for(int i = 0; i < B.length(); i++){
            count[B[i] - 'A']--;
            if(count[B[i] - 'A'] < 0){
                return false;
            }
        }

        return true;
    }
};

int main(){
    Solution s = Solution();
    // string A = "ABCD";
    // string B = "ACD";
    //string A = "ABCD";
    //string B = "AABC";
    string A, B;
    getline(cin, A, '\n');
    getline(cin, B, '\n');
    bool result = s.compareStrings(A, B);
    cout << result << endl;
}