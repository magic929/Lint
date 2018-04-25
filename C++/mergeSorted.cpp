#include<vector>
#include<iostream>

using namespace std;

vector<int> mergeSortArray(vector<int>&A, vector<int> &B){
    // 1. 从a,b左侧开始
    // 2. 比较a,b大小，小的进入新数组种
    // 3. 小的数组前进1位，新数组前进一位
    // 4. 重复2,3 直到某数组遍历完
    // 5. 把剩下的数组放入新数组。
    // 时间复杂度: O(n+k)=O(n)
    vector<int> result(A.size() + B.size(), 0);
    int i = 0, j = 0;
    int k = 0;
    while(i < A.size() && j < B.size()){
        if(A[i] > B[j]){
            result[k++] = B[j++];
        }
        else{
            result[k++] = A[i++];
        }
    }
    while(i < A.size()){
        result[k++] = A[i++];
    }
    while(j < B.size()){
        result[k++] = B[j++];
    }

    return result;
}

int main(){
    vector<int> A = {1, 2, 3, 4};
    vector<int> B = {2, 4, 5, 6};

    vector<int> result = mergeSortArray(A, B);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
}