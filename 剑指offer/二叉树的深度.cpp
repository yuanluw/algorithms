/*
输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）
形成树的一条路径，最长路径的长度为树的深度。
解题思路:
基础题 可使用层次遍历或后序遍历解决 
*/

#include<iostream>
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
	//后序遍历 递归版本 
    int TreeDepth(TreeNode* pRoot){
        if(pRoot == NULL)
			return 0;
		else{
			int left = TreeDepth(pRoot->left);
			int right = TreeDepth(pRoot->right);
			return left>right?left+1:right + 1;
		}
    }
    //层序遍历 迭代版本 
    int TreeDepth2(TreeNode* pRoot){
    	if(pRoot == NULL)
    		return 0;
    	queue<TreeNode*> q;
    	q.push(pRoot);
    	int depth=0, count=0, nextCount=1;
    	while(q.size()!=0){
    		TreeNode* temp = q.front();
    		q.pop();
    		if(temp->left)
    			q.push(temp->left);
    		if(temp->right)
    			q.push(temp->right);
    		count++;
    		//遍历完一层的结点 
    		if(count == nextCount){
    			nextCount = q.size();
    			count = 0;
    			depth++;
			}
		}
		return depth;
	}
};


int main(){
	
	
} 
