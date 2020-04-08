/*
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。n<=39

解题思路:
斐波那契数列即 F[n] = F(n-1) + F(n-2) f1 = f2 = 1
- 最简便的就是递归的方法， 但是随着n越来越大 迭代次数过多
- 动态规划的思想 用一个数组记录从f(1)开始每个数的值，但是本题只要求输出第n项的值，只使用两个变量记录f(n-1)和f(n-2)即可 
*/ 

#include<iostream>

using namespace std;

class Solution {
public:
    int Fibonacci(int n) {
        if(n == 1 || n == 2){
            return 1;
        }
        else{
        	int temp1=1, temp2=1, temp=0;
			for(int i=3; i<=n; i++){
				temp = temp1+temp2;
				temp1 = temp2;
				temp2 = temp;
			} 
			return temp;
		} 
    }
};


int main(){
	
	Solution s;
	cout<<s.Fibonacci(39);
	
	return 0;
}
