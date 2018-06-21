#include<iostream>
#include<string>
#include<stack>
#include<climits>

using namespace std;

/*
 题目：把字符串中的符合规范的数字变成数字，且在int范围种
 1. 用栈来存储字符串
 2. 如果开头是空格, 则不推入栈中
 3. 如果出现 + - 则用flag记录正负
 4. 出现数字就推入栈中，直到没有数字出现
 5. 判断栈是否为空，如果为空则返回0， 否则输出数字。且判断是否大于最大值
 6. 判断正负，如果为负，则用 0 - 当前值
*/
class Solution{
public:
    int atoi(string &str){
        // 1. 用栈来存储字符串
        stack<int> stk;
        int n = str.length();
        int i = 0;
        int result = 0, base = 1;
        bool flag = true;
        //2. 如果开头是空格, 则不推入栈中
        while(i < n && str[i] == ' '){
            i++;
        }
        //3. 如果出现 + - 则用flag记录正负
        if(str[i] == '-'){
            flag = false;
            i++;
        }
        if(str[i] == '+'){
            i++;
        }
        //4. 出现数字就推入栈中，直到没有数字出现
        while(i < n &&str[i] >= '0' && str[i] <= '9'){
            stk.push(str[i] - '0');
            i++;
        }

        //5. 判断栈是否为空，如果为空则返回0， 否则输出数字。且判断是否大于最大值
        if(stk.empty()){
            return 0;
        }
        else if(stk.size() == 1 && stk.top() == '-'){
            return 0;
        }
        else{
            while(!stk.empty()){
                // if(stk.size() == 1 && stk.top() == '-'){
                //     return 0 - result;
                // }

                if(INT_MAX - result < stk.top() * base){
                    if(flag){
                        return INT_MAX;
                    }
                    else{
                        return INT_MIN;
                    }
                }

                result += base * stk.top();
                stk.pop();
                base *= 10;
            }
        }
        //6. 判断正负，如果为负，则用 0 - 当前值
        if(flag){
            return result;
        }
        else{
            return 0 - result;
        }
        
    }
};

int main(){
    Solution s = Solution();
    //string str = "10";
    //string str = "-1";
    //string str = "123123123123123";
    //string str = "1.0";
    string str;
    cin >> str;
    int result = s.atoi(str);
    cout << result;
}