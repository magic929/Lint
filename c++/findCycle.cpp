#include<stack>
#include<vector>
#include<iostream>

using namespace std;

stack<int> mystack;
vector<vector<int>> results;
int root;


void dfs(vector<vector<bool>> &maps, int n, vector<bool> &visited, int d, int start) {

	mystack.push(start);
	visited[start] = true;

	for(int j = 0; j < maps.size(); j++){
		if (maps[start][j] == true) {
			if (d == n - 1 && root == j) {
				stack<int> stk(mystack);
				vector<int> tmp(mystack.size(), 0);
				for (auto i = tmp.rbegin(); i < tmp.rend(); i++) {
					*i = stk.top();
					stk.pop();
				}
				tmp.push_back(root);
				results.push_back(tmp);
			}
			if (!visited[j]) {
				dfs(maps, n, visited, d + 1, j);
			}
		}
	}

	visited[start] = false;
	mystack.pop();

}

void findCycle(vector<vector<bool>> &maps, vector<bool> visited, int n) {
	int i = 0;
	for (i = 0; i < maps.size(); i++) {
		root = i;
		if (!visited[i]) {
			dfs(maps, n, visited, 1, i);
		}
	}
}

int main() {
	int n = 3;
	vector<vector<bool>> maps = { { false, true, true, false },{ false, false, true, false },{ true, false, false, true },{ false, false, false, true } };
	vector<bool> visited(maps.size(), false);

	dfs(maps, n, visited, 1, 0);

	for (int i = 0; i < results.size(); i++) {
		for (int j = 0; j < results[i].size(); j++) {
			cout << results[i][j] << " ";
		}

		cout << '\n';
	}

}