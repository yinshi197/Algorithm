class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //1.终止条件
        if(root == p || root == q || root == nullptr) return root;
        
        //2.递归逻辑
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        //3.返回值
        if(left != nullptr && right != nullptr) return root;
        
        if(left != nullptr && right == nullptr) return left;
        else if(left == nullptr && right != nullptr) return right;
        else return nullptr;
    }
};