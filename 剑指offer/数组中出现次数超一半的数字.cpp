/*
��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}��
��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��
����˼·:
1 �������飬���������������ͬ�����������������ж����ʣ�µ������Ƿ��������һ�������������
2 ʹ��map ��¼ÿ��Ԫ�س��ֵĴ��� ��ĳ��Ԫ�س��ִ�������һ�����ϼ����� 
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
		//����û��Ԫ�� ���߸պ�ȫ�������� 
		if(s.empty())
			return 0;
		//�ж����µ�Ԫ���Ƿ������һ�����ϵĴ��� 
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
			//ͳ��ÿ�����ֳ��ִ��� 
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
