/*
����һ�ö��������������ö���������ת����һ�������˫������Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
����˼·:
ʹ�����������preNodeȥ��¼��������һ�����   
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
        //�������� 
        if(preNode){
            root->left = preNode;
            preNode->right = root;
        }
        preNode = root;
        convert(root->right, preNode);
	
	}
	//�ݹ�汾 
    TreeNode* Convert(TreeNode* pRootOfTree){
        if(pRootOfTree == NULL)
        	return NULL;
		TreeNode* preNode = NULL;
		convert(pRootOfTree, preNode);
		//�ҵ�����ͷ��� 
		while(preNode->left)
             preNode = preNode->left;
		return preNode; 
    }
    //�ǵݹ�汾 
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
				//preΪ�� �������������һ����� Ҳ������ı�ͷ 
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
