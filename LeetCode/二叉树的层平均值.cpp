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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> avgResult;
        vector<double> layerNodes;
        queue<TreeNode*> q;
        int cur=0, pre=1;
        if(root == NULL)
            return avgResult;

        q.push(root);
        
        while(!q.empty()){

            TreeNode* temp = q.front();
            q.pop();
            cur++;
            layerNodes.push_back(temp->val);
            if(temp->left){
                q.push(temp->left);
            }
                
            if(temp->right){
                q.push(temp->right);
            }
                
            if(cur == pre){
                pre += q.size();
                double avg = 0.0;
                for(int i=0; i<layerNodes.size(); i++)
                    avg += layerNodes[i];
                avgResult.push_back(avg/layerNodes.size());
                layerNodes.clear();
            }
        }
        return avgResult;

    }
};
