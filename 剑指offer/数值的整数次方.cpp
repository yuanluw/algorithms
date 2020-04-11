/*
����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η�����֤base��exponent��ͬʱΪ0
����˼·: �������㷨 
*/ 


#include<iostream>

using namespace std;

class Solution {
public:
    double Power(double base, int exponent) {
    	bool flag = false;//ָ���Ƿ�Ϊ�� 
    	if(base == 0){
    		return 0;
		}
		else if(exponent == 0){
			return 1;
		}
		else if(exponent < 0){
			exponent = -exponent;
			flag = true;
		} 
		double temp = 1;
		while(exponent){
			if(exponent&1){
				temp *= base;
			}
			base *= base;
			exponent >>= 1;
		}
		return flag? 1/temp:temp;
    }
};

int main(){
	
	Solution s;
	cout<<s.Power(3, -2);
	
	return 0;
}
