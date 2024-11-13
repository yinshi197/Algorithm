class Solution {
public:
    int maxDepth(Node* root) {
        if(root == nullptr) return 0;
        int depth = 0;
        for(int i = 0; i < root->children.size(); i++)
        {
            depth = max(maxDepth(root->children[i]), depth);
        }

        return depth + 1;
    }
};