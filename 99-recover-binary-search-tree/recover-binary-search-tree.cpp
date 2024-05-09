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
    TreeNode *prev, *first, *middle, *last;
    void solve(TreeNode *root) {
        if (root == NULL) return;
        solve(root -> left);

        if (prev != NULL and root -> val < prev -> val) {
            if (first == NULL) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }
        prev = root;

        solve(root -> right);
    }
public:
    void recoverTree(TreeNode* root) {
        prev = new TreeNode(INT_MIN);
        first = middle = last = NULL;
        solve(root);
        if (first != NULL and last != NULL) {
            int t = first -> val;
            first -> val = last -> val;
            last -> val = t;
        }
        else if (first != NULL and middle != NULL) {
            int t = first -> val;
            first -> val = middle -> val;
            middle -> val = t;
        }
    }
};