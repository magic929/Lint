#include<vector>
#include<string>
#include<sstream>
#include<queue>
#include<iostream>

using namespace std;

vector<string> split(const string &str, string delim);

//link
class TreeNode {
  public:
      int val;
      TreeNode *left, *right;
      TreeNode(int val) {
          this->val = val;
          this->left = this->right = NULL;
      }
  };
//Non-recursive Binary Tree Preorder Traversal
// 1. 把根节点放到数组中，然后依次放入左右子树，直到结束
// 2. 去数组中掉最后的NULL节点
// 3. 判断是否数组为空，为空则返回{}
// 4. 不为空，则依次输入节点数值，碰到null的时候输入#
string serialize(TreeNode *root){
    vector<TreeNode *> Q;
    Q.push_back(root);

    for(int i = 0; i < Q.size(); i++){
        TreeNode *node = Q[i];
        if(node == NULL){
            continue;
        }

        Q.push_back(node->left);
        Q.push_back(node->right);
    }

    while(Q.size() > 0 && Q[Q.size() - 1] == NULL){
        Q.pop_back();
    }

    if(Q.size() == 0){
        return "{}";
    }

    // make string 
    stringstream ss;
    ss << "{" << Q[0]->val;
    for(int i = 1; i < Q.size(); i++){
        if(Q[i] == NULL){
            ss << ",#";
        }
        else{
            ss << "," << Q[i]->val;
        }
    }
    
    ss << "}";

    return ss.str();
}
// 1. 根据，号分成字符串组
// 2. 创建堆栈来存储将要生成的二叉树
// 3. 如果没有到底，则依次生成左节点，并把左节点推入堆， 标记左节点
// 4. 生成右节点，并把右节点推入堆。标记左节点。并推出已经完成左右子节点的节点
// 5. 如果到底且左子节点以推入，则推出该节点
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

int main(){
    string str = "{3,9,20,#,#,15,7}";
    TreeNode *deserStr = deserialize(str);
    string result = serialize(deserStr);
    cout << result;
}