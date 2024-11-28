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
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == nullptr) return root;

        //将root移动到[low, high]
        while(root != nullptr && (root->val < low || root->val > high))
        {
            if(root->val < low) root = root->right;
            else if(root->val > high) root = root->left;
        }

        TreeNode *cur = root;
        //左孩子小于low的情况
        while(cur != nullptr)
        {
            while(cur->left && cur->left->val < low)
            {
                cur->left = cur->left->right;
            }

            cur = cur->left;
        }

        cur = root;
        //右孩子大于high
        while(cur != nullptr)
        {
            while(cur->right && cur->right->val > high)
            {
                cur->right = cur->right->left;
            }

            cur = cur->right;
        }

        return root;
    }   

    void traversal(TreeNode *cur, vector<int> &vec)
    {
        if(cur == nullptr) return;  
        
        traversal(cur->left, vec);  // 左
        vec.push_back(cur->val);    // 中
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

    int low, high;
    cin >> low >> high;

    TreeNode *root = createTree(test);

    Solution *so = new Solution();
    TreeNode *ret = so->trimBST(root, low, high);
    vector<int> vec = so->preorderTraversal(ret);
    
    for(auto i : vec)
    {
        cout << i << " ";
    }
    
    return 0;
}