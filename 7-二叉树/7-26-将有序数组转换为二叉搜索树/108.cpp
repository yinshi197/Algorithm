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
    TreeNode* traversalCreate(vector<int>& nums, int left, int right)
    {
        //1.终止条件
        if(left > right) return nullptr;
        
        int mid = left + (right - left) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = traversalCreate(nums, left, mid - 1);
        root->right = traversalCreate(nums, mid + 1, right);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return traversalCreate(nums, 0, nums.size() - 1);   
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
    vector<int> nums = {-10,-3,0,5,9};
    Solution *so = new Solution();
    TreeNode *ret = so->sortedArrayToBST(nums);
    vector<int> vec = so->preorderTraversal(ret);
    
    for(auto i : vec)
    {
        cout << i << " ";
    }
    
    return 0;
}