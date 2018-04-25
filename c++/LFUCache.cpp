#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;
int minFreq, cap;
unordered_map<int, pair<int, int>>m;
unordered_map<int, list<int>> freq;
unordered_map<int, list<int>::iterator> iter;

int get(int key){
    if(m.count(key) == 0) return -1;
    freq[m[key].second].erase(iter[key]);
    ++m[key].second;
    freq[m[key].second].push_back(key);
    iter[key] = --freq[m[key].second].end();
    if(freq[minFreq].size() == 0){
        ++minFreq;
    }
    return m[key].first;
}

void put(int key, int value){
    if(cap <= 0){
        return ;
    }
    if(get(key) != -1){
        m[key].first = value;
        return;
    }
    if(m.size() >= cap){
        m.erase(freq[minFreq].front());
        iter.erase(freq[minFreq].front());
        freq[minFreq].pop_front();
    }
    m[key] = {value, 1};
    freq[1].push_back(key);
    iter[key] = --freq[1].end();
    minFreq = 1;
}

int main(){
    cap = 3;
    minFreq = 0;
    put(2, 2);
    put(1, 1);
    int result = get(2);
    cout << result <<"\n";
    result = get(1);
    cout << result << "\n";
    result = get(2);
    cout << result << "\n";
    put(3, 3);
    put(4, 4);
    result = get(3);
    cout << result << "\n";
    result = get(2);
    cout << result << "\n";
    result = get(1);
    cout << result << "\n";
    result = get(4);
    cout << result << "\n";
}