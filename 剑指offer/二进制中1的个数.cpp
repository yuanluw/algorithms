/*
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

解题思路:
假设n=5:  0000 0000 0000 0000 0000 0000 0000 0000 0101   0110 1010  
    n=-5: 1111 1111 1111 1111 1111 1111 1111 1111 1011(取反加1) 
解法1: 用一个标志位与n的每一位进行与操作即可, 每次修改标志位 
解法2:  修改输入n 即每次右移一位，再判断n的最低位是否为0 不为0则加1 但直接右移对于负数会出现问题
		因为对负数进行算术右移是高位补1，所以陷入死循环。 可修改n的类型为unsigned型或者使用>>>(无符号右移)，此时右移为逻辑操作 不会陷入死循环 
解法3: 也是修改输入n，采用 n=(n-1)&n的方式来移位，n=(n-1)&n可实现每次将n最右边的第一个1置为0的功能，因
	   此执行多少次该式即代表有多少个1 

	   - 
*/ 
#include <iostream>

using namespace std;

class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0, index=1;
         for(int i=0;i<sizeof(int)*8;i++){
         	if(n & index){
         		count++;
			 }
			 index <<= 1;
		 }
		 return count;
     }
     
     int NumberOf2(int n){
     	int count = 0;
     	unsigned int nn = n; 
     	while(nn != 0){
			if (nn & 1)
     			count++;
     		nn >>= 1;
		 }
		 return count;
	 }
	 
	 int NumberOf3(int n){
     	int count = 0;
     	while(n != 0){
     		count++;
     		n = (n-1)&n;
		 }
		 return count;
	 }
};


int main(){
	
	Solution s;
	
	cout<<s.NumberOf3(-5);
	
	return 0;
}
