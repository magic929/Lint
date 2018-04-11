#include<string>
#include<iostream>
#include<vector>

using namespace std;

string helper(int mod, string w){
    return mod == 0? w : "";
}

vector<string> fizzBuzz(int n){
    vector<string> result;
    for(int i = 1 ; i <= n; i++){
        string tmp = helper(i % 3, "fizz") + helper(i % 15, " ") + helper(i % 5, "buzz");
        if(tmp == ""){
            result.push_back(to_string(i));
        }
        else{
            result.push_back(tmp);
        }
    }

    return result;
}

int main(){
    int n = 15;
    vector<string> result = fizzBuzz(15);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
}