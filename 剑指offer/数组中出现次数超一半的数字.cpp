/*
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
解题思路:
1 遍历数组，如果遇到两个不相同的数组则丢弃，再来判断最后剩下的数字是否满足出现一半以上这个条件
2 使用map 记录每个元素出现的次数 当某个元素出现次数大于一半以上即返回 
*/


#include<iostream>
#include<vector>
#include<stack>
#include<map>
using namespace std;


class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    	stack<int> s;
    	
    	for(int i=0;i<numbers.size();i++){
    		if(s.empty())
    			s.push(numbers[i]);
    		else{
    			int temp = s.top();
    			if(temp != numbers[i])
    				s.pop();
    			else
    				s.push(numbers[i]);
			}
    		
		}
		//代表没有元素 或者刚好全部抵消了 
		if(s.empty())
			return 0;
		//判断留下的元素是否出现了一半以上的次数 
		int temp = s.top(), count=0;
		for(int i=0;i<numbers.size();i++)
			if(numbers[i] == temp)
				count ++;
		if(count>numbers.size()/2)
			return temp;

		return 0;
    }
    
    int MoreThanHalfNum_Solution2(vector<int> numbers){
    	map<int, int> m;
		int count = 0;
		for(int i=0;i<numbers.size();i++){
			//统计每个数字出现次数 
			m[numbers[i]]++;
			if(m[numbers[i]]> numbers.size()/2)
				return numbers[i];
		} 
    	return 0;
	}
};


int main(){
	
	vector<int> numbers = {1,2,3,2,2,2,5,4,2};
	Solution s;
	cout<<s.MoreThanHalfNum_Solution2(numbers);
	
	return 0;
}
