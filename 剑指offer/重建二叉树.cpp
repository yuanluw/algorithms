/*
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

解题思路:
前序遍历的顺序是根节点 左分支 右分支，即可根据根节点值在中序结果中的位置将数据划分为左右分支
然后递归的划分即可得到完整的树 
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
		// 寻找根节点在中序的位置，从而分成左右分支 
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
		//递归更新 
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
