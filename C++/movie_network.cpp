#include<queue>
#include<map>
#include<iostream>
#include<algorithm>

using namespace std;

// which type is be puted in priority_queue
class node{
public:
    int rating;
    int id;
    bool operator < (const node &B) const{
        return rating > B.rating;
    }
    node(int a, int b): rating(a), id(b){}
};

// priority_queune
priority_queue<node>Q;
// vistied is true
map<int, bool>visit;

// find the target's all relation
// and sort under the limit K
void dfs(int u, int limit, vector<int> &rating, vector<vector<int>> &G, int S){
    visit[u] = true;
    if(u != S){
        if(Q.size() < limit || (rating[u] > Q.top().rating)){
            if(Q.size() == limit){
                Q.pop();
            }
            Q.push(node(rating[u], u));
        }
    }

    for(int i = 0; i < G[u].size(); i++){
        int v = G[u][i];
        if(visit[v] == false){
            dfs(v, limit, rating, G, S);
        }
    }
}

// get the result
vector<int> topKMovie(vector<int> &rating, vector<vector<int>> G, int S, int K){
    vector<int> ans;
    dfs(S, K, rating, G, S);
    while(!Q.empty()){
        ans.push_back(Q.top().id);
        Q.pop();
    }
    
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){

    vector<vector<int>> contactRelationshio;

    vector<int> ratingArray = {1, 2, 3, 4, 5};
    contactRelationshio.push_back(vector<int>{1, 3});
    contactRelationshio.push_back(vector<int>{0,2});
    contactRelationshio.push_back(vector<int>{1});
    contactRelationshio.push_back(vector<int>{0});

    vector<int> ans = topKMovie(ratingArray, contactRelationshio, 0, 2);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}