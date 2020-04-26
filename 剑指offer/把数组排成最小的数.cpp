/*
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
解题思路:
对数组进行排序 如a,b = 3, 32 a+b>b+a 所以两者应该调换位置。 
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
