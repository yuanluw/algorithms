/*
����һ�ö����������������ȡ��Ӹ���㵽Ҷ������ξ����Ľ�㣨������Ҷ��㣩
�γ�����һ��·�����·���ĳ���Ϊ������ȡ�
����˼·:
������ ��ʹ�ò�α�������������� 
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
	//������� �ݹ�汾 
    int TreeDepth(TreeNode* pRoot){
        if(pRoot == NULL)
			return 0;
		else{
			int left = TreeDepth(pRoot->left);
			int right = TreeDepth(pRoot->right);
			return left>right?left+1:right + 1;
		}
    }
    //������� �����汾 
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
    		//������һ��Ľ�� 
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
