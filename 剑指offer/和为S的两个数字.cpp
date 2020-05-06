/*
输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。

对应每个测试案例，输出两个数，小的先输出。
*/ 

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> result;
        if(array.size() < 2)
        	return result;
		int left=0, right=array.size()-1;
        //乘积最大 
        int a=array[right], b=array[right]; 
        
        while(left<right){
        	if(array[left] + array[right] == sum){
        		if(array[left]*array[right] < a*b){
        			a = array[left];
        			b = array[right];
				}
				left++;
			}
			else if(array[left] + array[right] > sum)
				right--;
			else
				left++;
        	
		}
		result.push_back(a);
		result.push_back(b);
		return result;
        
    }
};


int main(){
	
	vector<int> data = {1, 2, 3, 8, 9, 11};
	
	Solution s;
	vector<int> result = s.FindNumbersWithSum(data, 11);
	
	cout<<result[0]<<" "<<result[1]<<endl; 
	
	return 0;
}



