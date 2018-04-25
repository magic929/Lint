#include<string>
#include<iostream>
#include<vector>
#include<climits>

using namespace std;

string minWindow(string &source, string &target){
   /*vector<int> map(128, 0);
   for(auto c: target){
       map[c]++;
   }

   int counter = target.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
   
   while(end < source.size()){
       if(map[source[end++]]-- >= 0){
           counter--;
       }

       while(counter == 0){
           if(end - begin < d){
               d = end - begin;
               head = begin;
           }
           if(map[source[begin++]]++ == 0)  counter++;
       }
   }
   return d == INT_MAX ? "" : source.substr(head, d);*/
        vector<int> map(128,0);
        for (auto c : target) map[c]++;
        int counter = target.size(),begin = 0,end = 0,d = INT_MAX,head = 0;
        while (end < source.size()) {
            cout << "test4: " << begin << "\n";
            if (map[source[end++]]-- > 0) counter--;
            cout << "test3: " << begin<< "\n";
            while (counter == 0) {
                cout << "test2: " << begin<< "\n";
                if (end - begin < d) {
                    d = end - begin;
                    head = begin;
                    cout << "test: " << begin << "\n";
                }
                if (map[source[begin++]]++ == 0) counter++;
                cout << "test6: " << begin<< "\n";
            }
            cout << "test5: " << begin << "\n";
        }
        return d == INT_MAX ? "" : source.substr(head,d);
}

int main(){
    string source = "EADOBEC";
    string target = "ABC";

    string result = minWindow(source, target);
    /*for(int i = 0; i < result.size(); i++){
        cout << result[i];
    }*/
    cout << result;
}