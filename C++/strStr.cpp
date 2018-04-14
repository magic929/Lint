#include<iostream>
#include<string.h>

using namespace std;

int strStr(const char *source, const char *target){
    if(source == nullptr || target == nullptr){
        return -1;
    }

    int sl = strlen(source), tl = strlen(target);

    for(int i = 0; i <= sl - tl; i++){
        int j = 0;
        for(; j < tl; j++){
            if(source[i + j] != target[j]){
                break;        
            }
        }

        if(j == tl){
            return i;
        }
    }

     return -1;
}

int main(){
    const char *source = "abcdabcdefg";
    const char *target = "bcd";

    int result = strStr(source, target);
    cout << result;
}