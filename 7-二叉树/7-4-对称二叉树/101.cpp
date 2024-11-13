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
    bool isSymmetric(TreeNode* root) {
        stack<TreeNode*> st;
        if(root != nullptr)
        {
            st.push(root->left);
            st.push(root->right);
        }
        

        while(!st.empty())
        {
            TreeNode *left = st.top();
            st.pop();
            TreeNode *right = st.top();
            st.pop();
            
            if(!left && !right) continue;

            if((!left || !right || (left->val != right->val))) return false;

            st.push(left->left);
            st.push(right->right);
            st.push(left->right);
            st.push(right->left);
        }

        return true;
    }
};

//迭代法前序创建二叉树
TreeNode* createTree(vector<char>& nodes)
{
    if(nodes.empty() || nodes[0] == '#') return nullptr;

    TreeNode* root = new TreeNode(nodes[0] - '0');
    queue<TreeNode*> que;
    que.push(root);

    int i = 1;
    while(!que.empty() && i < nodes.size())
    {
        TreeNode* cur = que.front();
        que.pop();

        if(nodes[i] != '#')
        {
            cur->left = new TreeNode(nodes[i] - '0');
            que.push(cur->left);
        }
        i++;

        if(i < nodes.size() && nodes[i] != '#')
        {
            cur->right = new TreeNode(nodes[i] - '0');
            que.push(cur->right);
        }
        i++;
    }

    return root;
}

int main(int argc, char **argv)
{
    vector<char> test;
    char ch;
    while(cin >> ch)
    {
        if(ch == 'q') break;;
        test.push_back(ch);
    }
    TreeNode *root = createTree(test);
    Solution *so = new Solution();
    bool ret = so->isSymmetric(root);
    cout <<  ret << endl;
    
    return 0;
}