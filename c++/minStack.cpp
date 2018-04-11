#include<stack>
#include<iostream>

using namespace std;

stack<int> stk, minstk;

// create more one stack for saving the min number
void push(int number){
    stk.push(number);
    if(minstk.empty() || number <= minstk.top()){
        minstk.push(number);
    }
}

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