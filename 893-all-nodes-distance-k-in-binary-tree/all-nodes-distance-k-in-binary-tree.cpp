class Solution {
    void kDown(TreeNode* root, int k, TreeNode* blockNode, vector<int> &ans) {
        if (root == NULL || k < 0 || root == blockNode) return;
        if (k == 0) {
            ans.push_back(root -> val);
            return;
        }
        kDown(root -> left, k - 1, blockNode, ans);
        kDown(root -> right, k - 1, blockNode, ans);
    }
    int solve(TreeNode* root, TreeNode* target, int k, vector<int> &ans) {
        if (root == NULL) return -1;
        if (root == target) {
            kDown(root, k - 0, NULL, ans);
            return 1;
        }
        int left = solve(root -> left, target, k, ans);
        if (left != -1) {
            kDown(root, k - left, root -> left, ans);
            return left + 1;
        }
        int right = solve(root -> right, target, k, ans);
        if (right != -1) {
            kDown(root, k - right, root -> right, ans);
            return right + 1;
        }
        return -1;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        solve(root, target, k, ans);
        return ans;
    }
};