/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int maxTime = 0;
    void infectTree(TreeNode* root, TreeNode* blockNode, int time) {
        if (root == NULL || root == blockNode) return;

        maxTime = max(maxTime, time);

        infectTree(root -> left, blockNode, time + 1);
        infectTree(root -> right, blockNode, time + 1);
    }
    int solve(TreeNode* root, int start) {
        if (root == NULL) return -1;

        if (root -> val == start) {
            infectTree(root, NULL, 0);
            return 1;
        }
        int left = solve(root -> left, start);
        if (left != -1) {
            infectTree(root, root -> left, left);
            return left + 1;
        }
        int right = solve(root -> right, start);
        if (right != -1) {
            infectTree(root, root -> right, right);
            return right + 1;
        }
        return -1;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        solve(root, start);
        return maxTime;
    }
};