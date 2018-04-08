#include<algorithm>
#include<iostream>

using namespace std;

// ugly number feature:
// 2^i*3^j*5^k
int nthUglyNumber(int n){
    // the ugly array
    int *ugly = new int[n];
    ugly[0] = 1;
    // the count 2, 3, 5 
    int num2 = 0;
    int num3 = 0;
    int num5 = 0;

    for(int i = 1; i < n; i++){
        // compute the min from ugly * 2 or * 3 or * 5
        ugly[i] = min(min(ugly[num2]*2, ugly[num3]*3), ugly[num5]*5);
        // find the factor, the count 1 (array + 1)
        if(ugly[i] / ugly[num2] == 2){
            num2 ++;
        }
        if(ugly[i] / ugly[num3] == 3){
            num3 ++;
        }
        if(ugly[i] / ugly[num5] == 5){
            num5 ++;
        }
    }

    return ugly[n-1];
}

int main(){
    int n = 9; 
    int result = nthUglyNumber(n);
    cout << result << '\n';
}