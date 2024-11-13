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

    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ret;
        TreeNode* cur = root;
        while(cur != nullptr || !st.empty())	//使用或判断，因为cur可能为nullptr但是st里面还有节点(往回走)
        {
            if(cur != nullptr)
            {
                st.push(cur);
                cur = cur->left;    //左
            }
            else
            {
                cur = st.top();
                st.pop();
                ret.push_back(cur->val); //中
                cur = cur->right;   //右
            }
        }

        return ret;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> st;
        if(root == nullptr) return ret;
        st.push(root);
        
        while(!st.empty())
        {
            TreeNode *cur = st.top();
            ret.push_back(cur->val);
            st.pop();
            
            if(cur->left) st.push(cur->left);	//修改左右节点遍历顺序
            if(cur->right) st.push(cur->right);
        }

        reverse(ret.begin(), ret.end());	//翻转结果

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
    vector<int> ret = so->postorderTraversal(root);
    for(auto i : ret)
    {
        cout << i << " ";
    }

    return 0;
}