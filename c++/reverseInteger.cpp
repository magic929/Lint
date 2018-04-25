#include <iostream>

using namespace std;

class Solution{
    public:
        int reverseInteger(int number){
            int result = 0;

            while(number != 0){
                result = result * 10 + number % 10;
                number /= 10;
            }
            return result;
        }   
};

int main(){
    int number = 123;
    Solution s = Solution();
    int result = s.reverseInteger(number);
    cout << result;
}