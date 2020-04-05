/*
����ĳ��������ǰ���������������Ľ�������ؽ����ö�������
���������ǰ���������������Ľ���ж������ظ������֡�
��������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}�����ؽ������������ء�

����˼·:
ǰ�������˳���Ǹ��ڵ� ���֧ �ҷ�֧�����ɸ��ݸ��ڵ�ֵ���������е�λ�ý����ݻ���Ϊ���ҷ�֧
Ȼ��ݹ�Ļ��ּ��ɵõ��������� 
*/ 

#include<iostream> 
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    	int len = pre.size();

		if(len == 0){
			cout<<"NULL"<<endl;
    		return NULL;
		}

		
		TreeNode *head = new TreeNode(pre[0]);
		cout<<pre[0]<<endl;
		int index = 0;
		vector<int> left_pre, left_vin;
		vector<int> right_pre, right_vin;
		// Ѱ�Ҹ��ڵ��������λ�ã��Ӷ��ֳ����ҷ�֧ 
		for(int i=0; i<len; i++){
			if(vin[i] == pre[0]){
				index = i;
				break;
			}
		}  
		for(int i=0; i<index; i++){
			left_vin.push_back(vin[i]);
			left_pre.push_back(pre[1+i]);
		}
		for(int i=index+1; i<len; i++){
			right_vin.push_back(vin[i]);
			right_pre.push_back(pre[i]);
		}
		//�ݹ���� 
		head->left = reConstructBinaryTree(left_pre, left_vin);
		head->right = reConstructBinaryTree(right_pre, right_vin);
		return head;
		
		
    }
    
    void pre_reverse(TreeNode *root){
    	if(root == NULL){
    		return;
		}
		else{
			cout<<root->val<<endl;
			pre_reverse(root->left);
			pre_reverse(root->right);
		}
	}
};



int main(){
	
	vector<int> pre = {1,2,4,7,3,5,6,8};
	vector<int> vin= {4,7,2,1,5,3,8,6};
	Solution s;
	TreeNode *root = s.reConstructBinaryTree(pre, vin);
	s.pre_reverse(root);
	return 0;
}
