/*
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
解题思路:
使用中序遍历，preNode去记录遍历的上一个结点   
*/

#include<iostream>
#include<vector>
#include<stack>

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
	void convert(TreeNode* root, TreeNode* &preNode){
		if(root == NULL)
			return;
		
        convert(root->left, preNode);
        //更新链表 
        if(preNode){
            root->left = preNode;
            preNode->right = root;
        }
        preNode = root;
        convert(root->right, preNode);
	
	}
	//递归版本 
    TreeNode* Convert(TreeNode* pRootOfTree){
        if(pRootOfTree == NULL)
        	return NULL;
		TreeNode* preNode = NULL;
		convert(pRootOfTree, preNode);
		//找到链表头结点 
		while(preNode->left)
             preNode = preNode->left;
		return preNode; 
    }
    //非递归版本 
    TreeNode* Convert2(TreeNode* root){
    	
    	if(root == NULL)
    		return NULL;
    	
    	TreeNode *head = NULL, *pre = NULL;
    	stack<TreeNode*> s;
    	
    	while(root || !s.empty()){
    		
    		while(root){
    			s.push(root);
    			root = root->left; 
			}
			if(!s.empty()){
				root = s.top();
				s.pop();
				if(pre != NULL){
					pre->right = root;
					root->left = pre;
				}
				//pre为空 代表这是中序第一个结点 也是链表的表头 
				else{
					head = root;
				}
			}
			pre = root;
			root = root->right;
		}
    	return head;
    	
	}
};


int main(){
	
	TreeNode *root = new TreeNode(5);
	TreeNode *p1 = new TreeNode(2);
	TreeNode *p2 = new TreeNode(10);
	TreeNode *p3 = new TreeNode(4);
	TreeNode *p4 = new TreeNode(1);
	root->left = p1;
	p1->left = p4;
	p1->right = p3;
	root->right = p2;
	Solution s;
	TreeNode* head = s.Convert2(root);
	
	while(head){
		cout<<head->val<<" ";
		head = head->right;
	}
	
	return 0;
}
