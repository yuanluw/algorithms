/*
�����������һ����λָ�����ѭ�����ƣ�ROL���������и��򵥵�����
�������ַ���ģ�����ָ���������������һ���������ַ�����S���������ѭ��
����Kλ���������������磬�ַ�����S=��abcXYZdef��,Ҫ�����ѭ������3λ��Ľ����
����XYZdefabc�����ǲ��Ǻܼ򵥣�OK���㶨����
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

