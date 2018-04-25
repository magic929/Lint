#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool isInterleave(string &s1, string &s2, string &s3){
   if(s3.size() != s1.size() + s2.size()){
       return false;
   }
   vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
   dp[0][0] = true;
   for(int i = 1; i <= s1.size(); i++){
       dp[i][0] = (dp[i - 1][0] && (s3[i - 1] == s1[i - 1]));
   }
   for(int i = 1; i <= s2.size(); i++){
       dp[0][i] = (dp[0][i - 1] && (s3[i - 1] == s2[i - 1]));
   }

   for(int i = 1; i <= s1.size(); i++){
       for(int j = 1; j <= s2.size();j++){
           int t = i + j;
           if(s1[i - 1] == s3[t - 1]){
               dp[i][j] = dp[i][j] || dp[i - 1][j];
           }
           if(s2[j - 1] == s3[t - 1]){
               dp[i][j] = dp[i][j] || dp[i][j - 1];
           }
       }
   }
       return dp[s1.size()][s2.size()];
}

int main(){
    string s1 = "aabcc";
    string s2 = "dbbca";
    //string s3 = "aadbbcbcac";
    string s3 = "aadbbbaccc";
    int target = 3;

    bool result = isInterleave(s1, s2, s3);

    cout << result;
}