/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void post(TreeNode* &root, int &value){
        if(root == NULL)
            return ;
        
        post(root->right, value);
        root->val += value;
        value = root->val;
        post(root->left, value);
    }

    TreeNode* convertBST(TreeNode* root) {

        int value = 0;
        post(root, value);

        return root;
    }
};
