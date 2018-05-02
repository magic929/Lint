#include<stack>
#include<vector>
#include<iostream>
#include<sstream>
#include<string>

using namespace std;

/* line 算法题 - 有限图中长度为n的找圈
   深度优先查找
   1. 把当年的值压入堆栈
   2、一排一排遍历， 如果此时为true， 且长度为n，当前数值是最开始的数值的话，则找到一个圈
   3. 如果为真，且长度不到n则递归1
   4. 如果找到的都为假，则说明此处已无路则返回上一排继续找下面一个为真的数值，并且将推入栈的值推出
   5. 直到所有解被找到。
*/
class Soultion{
	public:
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
};


int main() {
	Soultion s = Soultion();
	string sn, sm;
	getline(cin, sn);
	getline(cin, sm);
	stringstream ssn(sn), ssm(sm);
	int n;
	vector<vector<bool>> maps;
	vector<bool> tmp;
	ssn >> n;
	vector<char> chars(sm.c_str(), sm.c_str() + sm.size() + 1);
	for(int i = 1; i < chars.size() - 1; i++){
		if(chars[i] == '{'){
			tmp.clear();
		}

		else if(chars[i] == '}'){
			maps.push_back(tmp);
		}
		else if(chars[i] == '0'){
			tmp.push_back(false);
		}
		else{
			tmp.push_back(true);
		}
	}
	// vector<vector<bool>> maps = { { false, true, true, false },{ false, false, true, false },{ true, false, false, true },{ false, false, false, true } };
	vector<bool> visited(maps.size(), false);

	s.findCycle(maps, visited, n);

	for (int i = 0; i < s.results.size(); i++) {
		for (int j = 0; j < s.results[i].size(); j++) {
			cout << s.results[i][j] << " ";
		}

		cout << '\n';
	}

}