/*
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
解题思路
1 直接从1加到n，考虑到不能使用循环，则采用递归来实现 
递归退出条件为n==0， 利用条件与的性质来实现
2 sum(1, n) = (n * n-1)/2, a*b可以利用位运算来实现 如a=2， b=5(二进制为101) 则a*b = a<<3 + a<<1  
*/

#include<iostream>

using namespace std;


class Solution {
public:
    int Sum_Solution(int n) {
        //当 n等于0时 && 后面程序即递归不会再执行 
        n && (n += Sum_Solution(n-1));
        return n;
    }
    
    int Sum_Solution2(int n){
		//>>1代表除2 
    	return mul(n, n+1)>>1;
	}
	
	int mul(int a, int b){
		int res = 0;
		//判断b的最低位是否为0  
		(b & 1) && (res += a);
		a <<= 1;
		b >>= 1;
		//while(b!=0){}
		b && (res += mul(a, b));
		return res;
	}
};


int main(){
	Solution s;
	cout<<s.Sum_Solution(3);
	
	return 0;
}

