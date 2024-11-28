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
    TreeNode* deleteNode(TreeNode* root, int key) {
        //1.终止条件
        if(root == nullptr) return root;    //情况1：没有找到要删除的节点

        //2.递归逻辑
        if(root->val > key) root->left = deleteNode(root->left, key);
        if(root->val < key) root->right = deleteNode(root->right, key);

        //2.1 删除操作
        if(root->val == key)
        {   
            //情况2：左右节点都为空
            if(root->left ==nullptr && root->right == nullptr)
            {
                delete root;
                return nullptr;
            }
            else if(root->left == nullptr)  //情况3：左节点空，右节点不为空
            {
                TreeNode *retNode = root->right;
                delete root;
                return retNode;
            }
            else if(root->right == nullptr) //情况4：右节点空，左节点不为空
            {
                TreeNode *retNode = root->left;
                delete root;
                return retNode;
            }
            else    //情况5：左右节点不为空
            {
                TreeNode *cur = root->right;
                while (cur->left != nullptr)
                {
                    cur = cur->left;
                }

                cur->left = root->left;
                TreeNode *temp = root;
                root = root->right;
                delete temp;

                return root;
            }
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

    int val;
    cin >> val;

    TreeNode *root = createTree(test);

    Solution *so = new Solution();
    TreeNode *ret = so->deleteNode(root, val);
    vector<int> vec = so->preorderTraversal(ret);
    
    for(auto i : vec)
    {
        cout << i << " ";
    }
    
    return 0;
}