#include<iostream>
#include<math.h>
#include<sstream>
using namespace std;

/*
1 4進数なら、4を割って、=3, より高い、より低い３種類を判断して。
2．結果を＋する
*/

long long digitCounts(long long n) {
        // write your code here
        long long result = 0;
        long long base = 1;
        
        while (n/base > 0) 
        {
            int cur = (n/base)%4;
            long long low = n - (n/base) * base;
            long long high = n/(base * 4);
            
            if (cur == 3) 
            {
                result += high * base + low + 1;
            } else if (cur < 3) 
            {
                result += high * base;
            } else
            {
                result += (high + 1) * base;
            }
            base *= 4;
        }
        
        return result;
    }

int main(int argc, char* argv[]){
    int idx;
    stringstream ss;
    ss << argv[1];
    ss >> idx;
    long long num = pow(4, idx);
    long long result = digitCounts(num);
    cout << result;
}
