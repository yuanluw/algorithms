/*
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。保证base和exponent不同时为0
解题思路: 快速幂算法 
*/ 


#include<iostream>

using namespace std;

class Solution {
public:
    double Power(double base, int exponent) {
    	bool flag = false;//指数是否为负 
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
