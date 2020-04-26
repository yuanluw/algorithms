/*
����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����
������������{3��32��321}�����ӡ���������������ųɵ���С����Ϊ321323��
����˼·:
������������� ��a,b = 3, 32 a+b>b+a ��������Ӧ�õ���λ�á� 
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


class Solution {
public:
	static bool cmp(int a, int b){
		string A = "", B = "";
		A += to_string(a) + to_string(b);
		B += to_string(b) + to_string(a);
		return A<B; 
	}
	
    string PrintMinNumber(vector<int> numbers) {
    	string answer = "";
		if(numbers.size() == 0)
    		return answer;
    	
    	sort(numbers.begin(), numbers.end(), cmp);
    	for(int i=0;i<numbers.size();i++){
    		answer += to_string(numbers[i]);
		}
    	return answer;
    }
};

int main(){
	
	vector<int> numbers = {3, 32, 321};
	Solution s;
	cout<<s.PrintMinNumber(numbers);
	
	return 0;
}
