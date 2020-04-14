/*
操作给定的二叉树，将其变换为源二叉树的镜像。
*/

#include<iostream>
#include <stack>
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
    void Mirror(TreeNode *pRoot) {
		if(pRoot == NULL || (pRoot->left == NULL && pRoot->right == NULL)){
			return ;
		}
		else{
			TreeNode *temp = pRoot->left;
			pRoot->left = pRoot->right;
			pRoot->right = temp;
			Mirror(pRoot->left);
			Mirror(pRoot->right);
		}
    }
    
    void Mirror2(TreeNode *pRoot){
    	stack<TreeNode*> s; 
    	if(pRoot == NULL){
    		return ;
		}
		s.push(pRoot);
		while(!s.empty()){
			TreeNode *root = s.top();
			s.pop();
			TreeNode *temp = root->left;
			root->left = root->right;
			root->right = temp;
			
			if(root->left)
				s.push(root->left);
			if(root->right)
				s.push(root->right);  	
		}
	}
};

int main(){
	
	return 0;
}
