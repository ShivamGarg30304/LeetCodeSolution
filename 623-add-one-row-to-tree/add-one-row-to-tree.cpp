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
public:
    void solve(TreeNode* root,int val,int depth)
    {
        if (root == NULL) return;
        cout << root -> val << " " << depth << endl;
        depth--;
        if(root->left)
        {
            solve(root->left,val,depth);
        }
        if(root->right)
        {
            solve(root->right,val,depth);
        }
        if(depth==0)
        {
            TreeNode *leftChild = root -> left;
            TreeNode *rightChild = root -> right;
            TreeNode *newLeftParent = new TreeNode(val);
            TreeNode *newRightParent = new TreeNode(val);
            root -> left = newLeftParent;
            newLeftParent -> left = leftChild;
            root -> right = newRightParent;
            newRightParent -> right = rightChild;
            // TreeNode* store1;
            // if(root->left)store1=root->left;
            // {TreeNode* a=new TreeNode(val);
            // root->left=a;
            // a->left=store1;}

            // TreeNode*store2;
            // if(root->right) store2=root->right;
            // {TreeNode* b=new TreeNode(val);
            // root->right=b;
            // b->right=store2;  
            
        }
        // if(depth==0 and root->left==NULL)
        // {
        //     TreeNode* a=new TreeNode(val);
        //     root->left=a;
        // }
        // if(depth==0 and root->right==NULL)
        // {
        //     TreeNode* b=new TreeNode(val);
        //     root->left=b;
        // }
        
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode *ans = new TreeNode(val);
            ans -> left = root;
            return ans;
            // ans -> right = root -> right;
            // return ans;
        }
        solve(root,val,depth-1);
        return root;
    }
};