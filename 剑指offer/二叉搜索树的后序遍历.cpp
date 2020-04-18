/*
����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ��������������Yes,�������No���������������������������ֶ�������ͬ��
����˼·:
	�����������������������н���С�ڸ���㣬���������н������ڸ��ڵ㡣����������������������е����һ�����T��Ϊ���ڵ�
	ƾ��T�ɰ�ʣ��Ľ���Ϊ������ ǰ�벿�ֱ�TС ��벿�ֱ�T�� �������ǺϷ��Ķ��������� 
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
			//�ҵ�root�����������߽� 
			for(index=0;index<len;index++){
				if(sequence[index] >= root_val)
					break;
			}
			//�������д���С��root�Ľ��������в��Ƕ��������� 
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
			//ֻʣ�²������������ʱ��Ȼ���϶���������Ҫ�� 
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
