#include<stack>
#include<iostream>
#include<string>
#include<regex>
#include<sstream>

using namespace std;

/*
  1. stk1保存新数据，stk2保存旧数据
  2. 如果有数据来就压入stk1中
  3. 如果要去掉最开头的数或者返回最开始的数，则使用stk2
  4. 如果stk2为空，则加入stk1中的数据，此时这些数据是最先进来的数据。
  5. 如果stk2不为空，则什么都不做。因为最先进来的数据还有
  6. stk2做一般的头部处理即可完成queue的工作
*/
class MyQueue{
public:
    stack<int> stk1, stk2;

    MyQueue(){
    }

    void push(int element){
        stk1.push(element);
    }

    int pop(){
        join();
        int result = stk2.top();
        stk2.pop();
        return result;
    }

    int top(){
        join();
        return stk2.top();
    }

    void join(){
        if(stk2.empty()){
            while(!stk1.empty()){
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
    }
};

int paser(smatch matchResult){
    stringstream ss(matchResult.str(1));
    int result;
    ss >> result;
    return result;
}

int main(){
    MyQueue q = MyQueue();
    string commad;
    smatch matchResult;
    while(1){
        getline(cin, commad);
        if(regex_match(commad, matchResult, regex("push\\(([0-9]+)\\)"))){
            q.push(paser(matchResult));
        }

        if(regex_match(commad, matchResult, regex("pop\\(\\)"))){
            int result = q.pop();
            cout << result <<'\n';
        }
        if(regex_match(commad, matchResult, regex("top\\(\\)"))){
            int result = q.top();
            cout << result << '\n';
        }
    }
    /*q.push(1);
    cout << q.pop() <<"\n";
    q.push(2);
    q.push(3);
    cout << q.top() << "\n";
    cout << q.pop() << "\n";*/
}