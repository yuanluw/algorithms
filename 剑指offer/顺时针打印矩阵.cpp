/*
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字
1 2 3 4 x             
5 6 7 8 x       
9 10 11 12 x
13 14 15 16 x

解题思路:
1. 每次打印过程都是一个圈，因此只要把握好圈的四个顶点，那可以进行多次迭代得到结果
2. 采用旋转数组的方法，每次取数组第一行的数据并删除，然后将该数组逆时针旋转90度即可 

*/

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	
    vector<int> printMatrix(vector<vector<int> > matrix) {
	    vector<int> result;
		int row=matrix.size(),  col= matrix[0].size();
		//判断数组是否异常 
		if(col == 0 || row == 0)
			return result;
		//得到四个顶点的位置 
		int left=0, top=0, right=col-1, down=row-1; 
		while((left <= right) && (top <= down)){
			for(int i=left; i<=right; i++)
				result.push_back(matrix[top][i]);
			for(int i=top+1;i<=down;i++)
				result.push_back(matrix[i][right]);
			//考虑出现单行或单列的情况 
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

