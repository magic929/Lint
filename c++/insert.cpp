#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Interval{
    public: 
        int start, end;
    Interval(int start, int end){
        this->start = start;
        this->end = end;
    }
};

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval){
    vector<Interval> ans;
    int st;
    for(st = 0; st < intervals.size() && intervals[st].start < newInterval.start; st++){
        ans.push_back(intervals[st]);
    }

    if(!ans.empty() && ans.back().end >= newInterval.start){
        ans.back().end = max(ans.back().end, newInterval.end);
    }
    else{
        ans.push_back(newInterval);
    }

    for(int i = st - 1; i < intervals.size(); i++){
        if(ans.back().end >= intervals[i].start){
            ans.back().end = max(ans.back().end, intervals[i].end);
        }
        else{
            ans.push_back(intervals[i]);
        }
    }

    return ans;
}

int main(){
    vector<Interval> intervals = {Interval(1, 2), Interval(5, 9)};
    /*for(int i = 0; i < intervals.size(); i++){
        cout << "test: " << intervals[i].start << " " << intervals[i].end << "\n";
    }*/
    //Interval newInterval = Interval(2, 5);
    Interval newInterval = Interval(3, 4);
    vector<Interval> results = insert(intervals, newInterval);
    for(int i = 0; i < results.size(); i++){
        cout << results[i].start << " " << results[i].end << "\n";
    }
}