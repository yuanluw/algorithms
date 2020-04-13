/*
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
解题思路
1. 层序遍历A树，当找到一个结点跟B树的根节点一样时，则继续顺序比较。 
*/ 

#include<iostream>
#include<string>
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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
	 	if(pRoot1==NULL || pRoot2==NULL) //空树返回false 
	 		return false;
	 	//从A的root开始跟B树继续比较 
	 	bool flag = isSubTree(pRoot1, pRoot2);
	 	if (!flag) 
	 		//A的root不匹配 则用A的左子树继续匹配 
	 		flag = HasSubtree(pRoot1->left, pRoot2);
	 	if (!flag)
	 		//左子树不匹配 用右子树继续匹配 
	 		flag = HasSubtree(pRoot1->right, pRoot2);
	 		
	 	return flag;	
    }
    bool isSubTree(TreeNode* p1, TreeNode* p2){
    	
    	if(p2 == NULL){
    		return true; //代表p2所有节点均匹配成功 
		}
    	
    	if(p1 == NULL)
    		return false; 
    	
    	if(p1->val != p2->val)
    		return false;
    	else{
    		return isSubTree(p1->left, p2->left) && isSubTree(p1->right, p2->right);
		}	
	}
	
	
	void  pre_tra(TreeNode* p, string s){
		
		if(p == NULL){
			return;
		}
		else{
			s += p->val;
			pre_tra(p->left);
			pre_tra(p->right);
		}
		
	}
	
	
	
};
