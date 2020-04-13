/*
�������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��
����˼·
1. �������A�������ҵ�һ������B���ĸ��ڵ�һ��ʱ�������˳��Ƚϡ� 
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
	 	if(pRoot1==NULL || pRoot2==NULL) //��������false 
	 		return false;
	 	//��A��root��ʼ��B�������Ƚ� 
	 	bool flag = isSubTree(pRoot1, pRoot2);
	 	if (!flag) 
	 		//A��root��ƥ�� ����A������������ƥ�� 
	 		flag = HasSubtree(pRoot1->left, pRoot2);
	 	if (!flag)
	 		//��������ƥ�� ������������ƥ�� 
	 		flag = HasSubtree(pRoot1->right, pRoot2);
	 		
	 	return flag;	
    }
    bool isSubTree(TreeNode* p1, TreeNode* p2){
    	
    	if(p2 == NULL){
    		return true; //����p2���нڵ��ƥ��ɹ� 
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
