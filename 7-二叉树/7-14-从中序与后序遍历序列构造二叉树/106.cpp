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
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder) {
        //1.非空判断
        if(postorder.size() == 0) return nullptr;

        //2.找到后序遍历的最后一个元素----根节点
        int rootval = postorder[postorder.size() -1];
        TreeNode *root = new TreeNode(rootval);

        if(postorder.size() == 1) return root;

        //3.在后序遍历中切割左右子树
        //3.1找到切割点
        int index = 0;
        for(index = 0; index < inorder.size(); index++)
        {
            if(inorder[index] == rootval) break;
        }

        //3.2 切割中序遍历
        //左开右闭
        vector<int> leftInorder(inorder.begin(), inorder.begin() + index);
        vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());

        //4. 切割后序数组, 后序数组没有明确的左右子树。按leftInorder、rightInorder大小切割。
        postorder.resize(postorder.size() - 1);
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        vector<int> rightPostorder( postorder.begin() + leftInorder.size(), postorder.end());

        //5.递归处理
        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0) return nullptr;

        return traversal(inorder, postorder);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        if(root != nullptr) que.push(root);
        vector<vector<int>> ret;

        while(!que.empty())
        {
            int size = que.size();  //记录size,后面会变化
            vector<int> vec;
            for(int i = 0; i < size; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                vec.push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }

            ret.push_back(vec);;
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
    Solution *so = new Solution();
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    vector<vector<int>> retvec;
    TreeNode *root = so->buildTree(inorder, postorder);
    retvec = so->levelOrder(root);
    for(auto vec : retvec)
    {   
        for(auto i : vec)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    
    return 0;
}