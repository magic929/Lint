#include<iostream>
#include<string.h>

using namespace std;

// KMP算法: 当匹配失败的时候，i不回溯，而是让j向前
// 1. 判断两个字符串是否为空，为空则返回-1
// 2. 算出target字符串的next表
//    2.1 当出现和开始顺序一致的字符串时+1。不匹配的时候为0
// 3. 当字符串和目标字符串不符合的时候，j就跳到next表里的位置
// 时间复杂度 O(k+n)

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
    }

    if(j == lengthT){
        return i - j;
    }

    return -1; 
}

int main(){
    const char* source = "source";
    const char* target = "target";

    int result = strStr(source, target);
    cout << result;
}