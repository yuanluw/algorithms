/*
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> result;
		queue<TreeNode*> q;
		if(root == NULL){
			return result;
		}
		q.push(root);
		while(!q.empty()){
			TreeNode* p = q.front();
			q.pop();
			result.push_back(p->val);
			if(p->left)
				q.push(p->left);
			if(p->right)
				q.push(p->right);
		}
		return result;
    }
    
};


int main(){
	
	return 0;
}
