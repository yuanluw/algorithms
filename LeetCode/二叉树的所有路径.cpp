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
private:

    string generateText(vector<int>s){

        string temp = to_string(s[0]);
        for(int i=1;i<s.size();i++){
            temp+= "->";
            temp.append(to_string(s[i]));
        }
        return temp;
    }

    void preOrder(vector<string>& result, vector<int> &s, TreeNode *root){

        if(root == NULL){
            return ;
        }
        else if(root->left==NULL && root->right==NULL){
            s.push_back(root->val);
            result.push_back(generateText(s));
            s.pop_back();
        }
        else{
            s.push_back(root->val);
            preOrder(result, s, root->left);
            s.pop_back();

            s.push_back(root->val);
            preOrder(result, s, root->right);
            s.pop_back();
        }
    }
public:


    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> result;

        vector<int> s;
        preOrder(result, s, root);

        return result;

    }
};
