/*
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，
就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你把其循环
左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，
即“XYZdefabc”。是不是很简单？OK，搞定它！
*/

#include<iostream>
#include<string>

using namespace std;


class Solution {
public:
	
	void RotateString(string &str, int left, int right){
		
		while(left < right){
			char temp = str[left];
			str[left] = str[right];
			str[right] = temp;
			left++;
			right--;
		}
		
	}
	
    string LeftRotateString(string str, int n) {
        if(n > str.size() || n == 0)
        	return str;
        RotateString(str, 0, n-1);
        RotateString(str, n, str.size()-1);
        RotateString(str, 0, str.size()-1);
        return str;
        
    }
};

int main(){
	
	string str = "abcXYZdef";
	
	Solution s;
	cout<<s.LeftRotateString(str, 3);
	
	
}

