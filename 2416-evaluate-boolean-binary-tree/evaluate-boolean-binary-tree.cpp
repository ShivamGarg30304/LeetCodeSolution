class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if (root -> left == NULL and root -> right == NULL) return root -> val;
        int left = evaluateTree(root -> left);
        int right = evaluateTree(root -> right);
        if (root -> val == 2) return left | right;
        else return left & right;
    }
};