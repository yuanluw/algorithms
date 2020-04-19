/*
����һ�Ŷ������ĸ��ڵ��һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����
·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����(ע��: �ڷ���ֵ��list�У����鳤�ȴ�����鿿ǰ)
����˼·:
���������������������Ҷ�ڵ�ʱ�ж��Ƿ����������������򽫸�·����¼���� 
*/


#include<iostream>
#include<vector>
#include<algorithm>

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
	
	void FindPath(TreeNode* root, int expectNumber, vector<vector<int>> &result, vector<int> &node_list){
		expectNumber -= root->val;
		node_list.push_back(root->val);
		//�ж��Ƿ���������  
		if(expectNumber == 0 && root->left == NULL && root->right == NULL){
			result.push_back(node_list);
			node_list.pop_back();
			return;
		}
		if(root->left)
			FindPath(root->left, expectNumber, result, node_list);
		if(root->right)
			FindPath(root->right, expectNumber, result, node_list);
		//������һ�� 
		node_list.pop_back();
	}
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
    	vector<vector<int>> result;
		vector<int> node_list;
		if(root == NULL){
			return result;
		}
		FindPath(root, expectNumber, result, node_list);
		//���� 
		sort(result.begin(), result.end(), [](vector<int> a, vector<int> b) -> bool { return a.size() > b.size(); });
		return result;
    }
};


int main(){
	
	TreeNode* root = new TreeNode(10); 
	root->left = new TreeNode(12);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(7);
	root->right = new TreeNode(12);
	
	Solution s;
	vector<vector<int>> result = s.FindPath(root, 22);
	
	return 0;
}


