/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
解题思路:
	二叉搜索树满足左子树所有结点均小于根结点，右子树所有结点均大于根节点。而二叉搜索树后序遍历序列的最后一个结点T即为根节点
	凭借T可把剩余的结点分为两部分 前半部分比T小 后半部分比T大 这样才是合法的二叉搜索树 
*/

#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
		if(sequence.size() == 0){
			return false;
		}
		else{
			int len = sequence.size();
			int root_val = sequence[len-1];
			int index = 0;
			//找到root的左右子树边界 
			for(index=0;index<len;index++){
				if(sequence[index] >= root_val)
					break;
			}
			//右子树中存在小于root的结点则该序列不是二叉搜索树 
			for(int j=index;j<len-1;j++){ 
				if(sequence[j] < root_val)  
					return false;
			}
			vector<int> leftSequence, rightSequence;
			for(int i=0;i<index;i++)
				leftSequence.push_back(sequence[i]);
			for(int i=index;i<len-1;i++)
				rightSequence.push_back(sequence[i]);
			
			bool left=true, right=true;
			//只剩下不超过两个结点时必然复合二叉搜索树要求 
			if(leftSequence.size()>2) left = VerifySquenceOfBST(leftSequence);
			if(!left)
				return false;
			if(rightSequence.size()>2) right = VerifySquenceOfBST(rightSequence);
			return right;
		}	
    }
};


int main(){
	
	vector<int> a = {5,4,11, 10, 7, 1};
	Solution s;
	cout<<s.VerifySquenceOfBST(a);
	
	return 0;
}
