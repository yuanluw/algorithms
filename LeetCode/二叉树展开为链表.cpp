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

    TreeNode* pre(TreeNode* root){
        if(root == NULL)
            return NULL;
        else if(root->left == NULL && root->right == NULL){
            return root;
        }

        TreeNode* left = pre(root->left);
        TreeNode* right = pre(root->right);
        root->left = NULL;
        if(left != NULL){
            root->right = left;
            while(left->right != NULL)
                left = left->right;
            left->right = right;
            
        }
        else
            root->right = right;

        
        return root;
    }

    void flatten(TreeNode* root) {
        
        pre(root);
    }
};
