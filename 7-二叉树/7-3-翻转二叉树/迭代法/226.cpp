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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;

        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            swap(node->left, node->right);
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        }

        return root;
    }

    //前序遍历
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ret;
        if(root == nullptr) return ret;	//空节点不入栈
        st.push(root);

        while(!st.empty())
        {
          TreeNode* cur = st.top();
          st.pop();
          ret.push_back(cur->val);

          if(cur->right) st.push(cur->right);	//右节点先进栈，这样出栈顺序才是正确的。
          if(cur->left) st.push(cur->left);
        }

        return ret;
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
    vector<int> ret = so->preorderTraversal(root);
    for(auto i : ret)
    {
        cout << i << " ";
    }
    cout << endl;
    root = so->invertTree(root);
    ret = so->preorderTraversal(root);
    for(auto i : ret)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}