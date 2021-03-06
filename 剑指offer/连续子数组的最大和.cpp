/*
HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,他又发话了:
在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},连
续子向量的最大和为8(从第0个开始,到第3个为止)。给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)

*/

#include<iostream>
#include<vector>

using namespace std;

class Solution{
	
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		
		if(array.size() == 0)
			return 0;
		
		int max=0x80000000; //int的最小值 
		int temp = 0;
		for(int i=0; i<array.size(); i++){
			temp += array[i];
			
			//当前值大于max， 更新 
			if(temp > max)
				max = temp;
			
			if(temp<0)
				temp = 0;
		}
		return max;
	}
};

int main(){
	
	vector<int> array = {1,-2,3,10,-4,7,2,-5};
	
	Solution s;
	cout<<s.FindGreatestSumOfSubArray(array);
	
	return 0;
	
}
