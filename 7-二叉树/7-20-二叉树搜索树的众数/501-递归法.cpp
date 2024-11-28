#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    vector<int> ret;
    int count = 1;
    int maxCount = 1;
    TreeNode* pre = nullptr;

    void traversal(TreeNode* root)
    {
        if(root == nullptr) return;

        traversal(root->left);
        if(pre != nullptr && pre->val == root->val)
        {
            count++;
        }
        else count = 1;
        pre = root;

        if(count == maxCount) ret.push_back(root->val);
        if(count > maxCount)
        {
            ret.clear();
            maxCount = count;
            ret.push_back(root->val);
        }

        traversal(root->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        traversal(root);
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
    vector<int> ret = so->findMode(root);
    for(auto i : ret)
    {
        cout << i << endl;
    }
    
    return 0;
}