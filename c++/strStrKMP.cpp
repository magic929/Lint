#include<iostream>
#include<string.h>

using namespace std;

int* getNext(const char *target){
    int* next = new int[strlen(target)];
    int k = -1;
    int j = 0;
    next[0] = -1;
    while(j < strlen(target)){
        if(k == -1 || target[j] == target[k]){
            next[++j] = ++k;
        }

        else{
            k = next[k];
        }
    }
    return next; 
}

int strStr(const char *source, const char *target){
    if(source == nullptr || target == nullptr){
        return -1;
    }

    int lengthS = strlen(source);
    int lengthT = strlen(target);
    int i = 0, j = 0;
    int* next = getNext(target);
    while(i < lengthS && j < lengthT){
        if(j == -1 || source[i] == target[j]){
            i++;
            j++;
        }
        else{
            j = next[j];
        }

        if(j == lengthT){
            return i - j;
        }
    }

    return -1; 
}

int main(){
    const char* source = "abcdabcdefg";
    const char* target = "bcd";

    int result = strStr(source, target);
    cout << result;
}