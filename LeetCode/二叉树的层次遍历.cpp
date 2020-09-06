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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>> result;
        if(root == NULL)
            return result;

        int level = 0;
        int pre=1, cur=0;
        queue<TreeNode*> q;
        vector<int> t;
        
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            t.push_back(temp->val);
            cur++;
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            if(cur == pre){
                level++;
                result.push_back(t);
                t.clear();
                pre += q.size();
            }
        }
        reverse(result.begin(), result.end());
        return result;

    }
};
