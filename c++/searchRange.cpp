#include<vector>
#include<iostream>
#include<queue>

using namespace std;

vector<string> split(const string &str, string delim);

vector<int> result;

class TreeNode {
  public:
      int val;
      TreeNode *left, *right;
      TreeNode(int val) {
          this->val = val;
          this->left = this->right = NULL;
      }
  };
// 
TreeNode *deserialize(string data){
    if(data == "{}"){
        return NULL;
    }

    vector<string> vals = split(data.substr(1, data.size() - 2), ",");
    TreeNode *root = new TreeNode(atoi(vals[0].c_str()));
    queue<TreeNode *> Q;
    Q.push(root);

    bool isLeftChild = true;
    //first in first out
    for(int i = 1; i < vals.size(); i++){
        if(vals[i] != "#"){
            TreeNode *node = new TreeNode(atoi(vals[i].c_str()));
            if(isLeftChild){
                Q.front()->left = node;
            }
            else{
                Q.front()->right = node;
            }
            Q.push(node);
        }
        if(!isLeftChild){
            Q.pop();
        }

        isLeftChild = !isLeftChild;
    }
    return root;
}

vector<string> split(const string &str, string delim){
    vector<string> results;
    int lastIndex = 0, index;
    while((index = str.find(delim, lastIndex)) != string::npos){
        results.push_back(str.substr(lastIndex, index - lastIndex));
        lastIndex = index + delim.length();
    }

    if(lastIndex != str.length()){
        results.push_back(str.substr(lastIndex, str.length() - lastIndex));
    }
    
    return results;
}


void helper(TreeNode *node, int k1, int k2){
    if(node == NULL){
        return ;
    }

    helper(node->left, k1, k2);

    if(node->val >= 10 && node->val <= 22){
        result.push_back(node->val);
    }
    helper(node->right, k1, k2);
}
// 题目要求是从小到大排列，根据给出的测试集目视为中序遍历
// 1. 递归左子树到底
// 2. 判断此节点的数值是不是在范围之内
// 3. 把符合条件的数值推入容器
// 4. 开始遍历右子树到底
// 时间复杂度：O(n)
void searchRange(TreeNode *root, int k1, int k2){
    helper(root, k1, k2);
}

int main(){
    string tree = "{20,8,22,4,12,#,#,#,#}";
    TreeNode *test = deserialize(tree);
    int k1 = 10;
    int k2 = 22;

    searchRange(test, k1, k2);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
}