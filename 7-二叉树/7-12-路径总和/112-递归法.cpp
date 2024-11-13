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
    bool traversal(TreeNode* root, int targetSum)
    {
        if(!root->left && !root->right && targetSum == 0) return true;
        if(!root->left && !root->right) return false;

        if(root->left)
        {
            if(traversal(root->left, targetSum - root->left->val))
            return true;
        }
        if(root->right) 
        {
            if(traversal(root->right, targetSum - root->right->val))
            return true;
        }

        return false;
    }
        
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return traversal(root, targetSum - root->val);
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
    bool ret = so->hasPathSum(root, 22);
    cout << ret << endl;
    return 0;
}