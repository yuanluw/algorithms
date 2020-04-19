/*
输入一颗二叉树的根节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。(注意: 在返回值的list中，数组长度大的数组靠前)
解题思路:
采用先序遍历，当遍历到叶节点时判断是否满足条件，如是则将该路径记录下来 
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
		//判断是否满足条件  
		if(expectNumber == 0 && root->left == NULL && root->right == NULL){
			result.push_back(node_list);
			node_list.pop_back();
			return;
		}
		if(root->left)
			FindPath(root->left, expectNumber, result, node_list);
		if(root->right)
			FindPath(root->right, expectNumber, result, node_list);
		//返回上一层 
		node_list.pop_back();
	}
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
    	vector<vector<int>> result;
		vector<int> node_list;
		if(root == NULL){
			return result;
		}
		FindPath(root, expectNumber, result, node_list);
		//排序 
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


