#include<iostream>
#include<string>

using namespace std;

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