#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void traversal(TreeNode* cur, string path, vector<string>& ret)
    {
        path += to_string(cur->val);
        if(cur->left == nullptr && cur->right == nullptr)
        {
            ret.push_back(path);
            return;
        }

        //path + "->" 作为参数传入，没有改变path的值，相当于执行函数后自动回溯了
        //path1(函数执行的path) = path + "->";
        if(cur->left) traversal(cur->left, path + "->", ret);   //左
        if(cur->right) traversal(cur->right, path + "->", ret); //右
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        vector<string> ret;
        if(root == nullptr) return ret;

        traversal(root, path, ret);

        return ret;
    }
};

//迭代法前序创建二叉树
// 辅助函数，用于从数组创建二叉树
TreeNode* createTree(const std::vector<int*>& nodes)
{
    if (nodes.empty() || nodes[0] == nullptr) return nullptr;

    TreeNode* root = new TreeNode(*nodes[0]);
    std::queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size())
    {
        TreeNode* current = q.front();
        q.pop();

        if (nodes[i] != nullptr)
        {
            current->left = new TreeNode(*nodes[i]);
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != nullptr)
        {
            current->right = new TreeNode(*nodes[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

int main(int argc, char **argv)
{
    vector<int*> test;
    string ch;
    while(cin >> ch)
    {
        if(ch == "q") break;
        if(ch == "#" || ch == "null" || ch == "nullptr" || ch == "NULL")
        {
            test.push_back(nullptr);
        }
        else test.push_back(new int(stoi(ch)));
    }
    TreeNode *root = createTree(test);
    Solution *so = new Solution();
    vector<string> ret = so->binaryTreePaths(root);
    for(auto s : ret)
    {
        cout << s << endl;
    }
    return 0;
}