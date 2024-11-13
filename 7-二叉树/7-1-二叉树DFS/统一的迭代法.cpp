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

//统一迭代法,使用null标记访问过但未处理的节点
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> st;
        if(root != nullptr) st.push(root);

        while(!st.empty())
        {
            TreeNode *node = st.top();  //每次都是从左节点进入下一层
            if(node)
            {
                st.pop();
                if(node->right) st.push(node->right);   //加入右节点

                st.push(node);  //加入中间节点
                st.push(nullptr);   //标记中间节点访问过，但是没有处理

                if(node->left) st.push(node->left); //最后加入左节点
            }
            else
            {
                st.pop();   //弹出空节点
                node = st.top();
                st.pop();

                ret.push_back(node->val);
            }
        }

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
    vector<int> ret = so->inorderTraversal(root);
    for(auto i : ret)
    {
        cout << i << " ";
    }

    return 0;
}