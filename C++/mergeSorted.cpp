#include<vector>
#include<iostream>

using namespace std;

vector<int> mergeSortArray(vector<int>&A, vector<int> &B){
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