#include<stack>
#include<iostream>

using namespace std;

stack<int> stk, minstk;

// create more one stack for saving the min number
// 1. 推入堆栈一个数值，并判断该数值在最小堆栈中是不是小于top中的值
// 2. 如果小于则推入最小堆栈中
void push(int number){
    stk.push(number);
    if(minstk.empty() || number <= minstk.top()){
        minstk.push(number);
    }
}

// 1. 判断堆栈中top得值
// 2. 如果该值等于最小堆栈的top值，则最小堆栈推出。
// 3. 原堆栈推出
// 4. 返回top数值
int pop(){
    // stack.top return inserted number (a first in last out) 
    int top = stk.top();
    stk.pop();
    if(top == minstk.top()){
        minstk.pop();
    }

    return top;
}

int min(){
    return minstk.top();
}

int main(){
    push(1);
    pop();
    push(2);
    push(3);
    cout << min() << " ";
    push(1);
    cout << min() << " ";
}