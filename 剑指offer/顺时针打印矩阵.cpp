/*
����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ������
1 2 3 4 x             
5 6 7 8 x       
9 10 11 12 x
13 14 15 16 x

����˼·:
1. ÿ�δ�ӡ���̶���һ��Ȧ�����ֻҪ���պ�Ȧ���ĸ����㣬�ǿ��Խ��ж�ε����õ����
2. ������ת����ķ�����ÿ��ȡ�����һ�е����ݲ�ɾ����Ȼ�󽫸�������ʱ����ת90�ȼ��� 

*/

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	
    vector<int> printMatrix(vector<vector<int> > matrix) {
	    vector<int> result;
		int row=matrix.size(),  col= matrix[0].size();
		//�ж������Ƿ��쳣 
		if(col == 0 || row == 0)
			return result;
		//�õ��ĸ������λ�� 
		int left=0, top=0, right=col-1, down=row-1; 
		while((left <= right) && (top <= down)){
			for(int i=left; i<=right; i++)
				result.push_back(matrix[top][i]);
			for(int i=top+1;i<=down;i++)
				result.push_back(matrix[i][right]);
			//���ǳ��ֵ��л��е���� 
			if(top!=down)
				for(int i=right-1;i>=left;i--)
					result.push_back(matrix[down][i]);
			if(left!=right)
				for(int i=down-1;i>top;i--)
					result.push_back(matrix[i][left]);
			
			left+=1, right-=1, top+=1, down-=1;
		}
		return result;
    }
};


int main(){
	int a[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}; 
	
	Solution s;
	s.printMatrix(a);
	
	return 0;
	
}

