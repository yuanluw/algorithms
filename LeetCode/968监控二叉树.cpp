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

    int post(TreeNode* root, int &ans){

        if(!root)
            return 2;
        
        int l = post(root->left, ans);
        int r = post(root->right, ans);

        if(l==2 && r==2){
            return 0;
        }
        else if(l == 0 || r == 0){
            ans ++;
            return 1;
        }
        else{
            return 2;
        }
    }

    int minCameraCover(TreeNode* root) {

        int ans=0;
        if(root == NULL)
            return 0;
        if(post(root, ans) == 0){
            ans += 1;
        }
        
        return ans;

    }
};
