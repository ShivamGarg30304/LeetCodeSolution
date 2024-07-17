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
    vector<TreeNode*> ans;
    void dfs(TreeNode* root, unordered_set<int> &st, bool isRoot) {
        if (root == NULL) return;
        if (st.find(root -> val) != st.end()) {
            dfs(root -> left, st, true);
            dfs(root -> right, st, true);
        } else {
            if (isRoot) ans.push_back(root);
            TreeNode* leftChild = root -> left;
            TreeNode* rightChild = root -> right;
            if (leftChild) {
                if (st.find(leftChild -> val) != st.end()) {
                    root -> left = NULL;
                }
            }
            if (rightChild) {
                if (st.find(rightChild -> val) != st.end()) {
                    root -> right = NULL;
                }
            }
            dfs(leftChild, st, false);
            dfs(rightChild, st, false);
        }
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st(to_delete.begin(), to_delete.end());
        ans = vector<TreeNode*>(0);
        dfs(root, st, true);
        return ans;
    }
};