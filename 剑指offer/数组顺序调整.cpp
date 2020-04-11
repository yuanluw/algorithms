/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/ 

#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
	//方法1 
    void reOrderArray(vector<int> &array) {
        	
        int left=0;
        while(left < array.size()){
        	
        	//从头找到第一个偶数 
        	while(array[left]%2)
        		left++;
        	//向后寻找第一个奇数 
        	int right = left+1; 
        	while((array[right]%2)==0 && right<array.size())
        		right++;
        	//已经遍历完数组则退出 
        	if(right<array.size()){
        		int temp = array[right];
        		for(int i=right; i>left;i--){
        			array[i] = array[i-1];
				}
				array[left] = temp;
				left++;
			} 
        	else
        		break;
		}
        
    }
    //方法2 
    void reOrderArray2(vector<int> &array){
    	vector<int> temp;
    	
    	for(vector<int>::iterator iter=array.begin(); iter!=array.end();){
    		if(*iter % 2 == 0){
    			temp.push_back(*iter);
    			array.erase(iter);
			}
			else
				iter++;
		}
		for(vector<int>::iterator iter=temp.begin(); iter!=temp.end(); iter++){
			array.push_back(*iter);
		}
	}
};


int main(){
	
	vector<int> a = {5,9,2,3,8,1,0,3,4};
	Solution s;
	
	s.reOrderArray2(a);
	
	for(vector<int>::iterator iter=a.begin(); iter!=a.end(); iter++){
		cout<<*iter<<endl;
	}
	
	return 0;
	
}
