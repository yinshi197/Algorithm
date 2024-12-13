#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode() : val(0) {}
    TreeNode(int val)  : val(val) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
};

class Solution {
public:
    int ret;

    int traversal(TreeNode* root)
    {   
        //0：无覆盖
        //1: 有摄像头
        //2: 有覆盖
        if(root == nullptr) return 2;

        int left = traversal(root->left);
        int right = traversal(root->right);

        if(left == 2 &&  right == 2) return 0;
        if(left == 0 || right == 0) 
        {
            ret++;
            return 1;
        }

        if(left == 1 || right == 1) return 2;

        return -1;
    }

    int minCameraCover(TreeNode* root) {
        ret = 0;
        //遍历结束头节点没有覆盖
        if(traversal(root) == 0) ret++;

        return ret;
    }
};

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

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

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
    int ret = so->minCameraCover(root);
    cout << ret << endl;

    return 0;
}