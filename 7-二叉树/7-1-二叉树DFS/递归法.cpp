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

//递归法只需要修改节点顺序就可以实现前、中、后序的遍历
class Soilution
{
public:
    void traversal(TreeNode *cur, vector<int> &vec)
    {
        if(cur == nullptr) return;  
        vec.push_back(cur->val);    // 中
        traversal(cur->left, vec);  // 左
        traversal(cur->right, vec); // 右
    }

    //前序遍历
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        traversal(root, ret);

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
    Soilution *so = new Soilution();
    vector<int> ret = so->preorderTraversal(root);
    for(auto i : ret)
    {
        cout << i << " ";
    }

    return 0;
}