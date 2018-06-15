#include<string>
#include<iostream>

using namespace std;

class Solution{
public:
    void sortLetters(string &chars){
        int n = chars.length();
        int i = -1, j = n;
        while(i < j){
            while(i < j && chars[++i] >='a');
            while(i < j && chars[--j] <= 'Z');
            if(i < j){
                char tmp = chars[j];
                chars[j] = chars[i];
                chars[i] = tmp;
            }
        }
    }
};

int main(){
    Solution s = Solution();
    string chars = "abAcD";
    s.sortLetters(chars);
    cout << chars << endl;
}