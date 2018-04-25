#include<iostream>
#include<string>

using namespace std;

// 1. 求出offset后面的字符串长度
// 2. 生成字符串头到offset的子字符串和从offset到字符串尾的子字符串
// 3. 2里生成的字符串相加
// 时间复杂度O(n)
void rotateString(string &str, int offset){
    if(str.size() == 0){
        return ;
    }

    offset = offset % str.size();
    str = str.substr(str.size() - offset, str.size()) + str.substr(0, str.size() - offset);
}

int main(){
    string str = "abcdefg";
    int offset = 3;
    rotateString(str, offset);
    cout << str;
}