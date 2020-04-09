/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
解题思路: 
如果当前只跳了1级台阶，则剩下还有f(n-1)种， 如果跳了两级台阶 则剩下还有f(n-2)种， 
因此f(n) = f(n-1)+f(n-2) 且f(1)=1 f(2)=2，因此该题类似于一个斐波拉契数列 

题目难度升级: 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
解题思路：
此时没有了跳几级的限制 那么f(n) = f(0) + f(1) + ... + f(n-1) 即为从一次跳n级到只跳一级这么多种情况
f(0) 代表直接跳n级那么只有一种情况 =1 
f(1) = 1
f(2) =2
f(3) 可分为 f(0)+f(1)+f(2)= 1+1+2=4  
f(4) 可分为 f(0)+f(1)+f(2)+f(3) = 1+1+2+4=8
...
即f(n)等于前面各项之和+1 可迭代解决该问题 
*/ 

#include<iostream>

using namespace std;

class Solution {
public:
    int jumpFloor(int number) {
        if(number == 1){
        	return 1;
		}
		else if(number == 2){
			return 2;
		}
		else{
			int temp1=1, temp2=2, temp=0;
			for(int i=3; i<=n; i++){
				temp = temp1+temp2;
				temp1 = temp2;
				temp2 = temp;
			} 
			return temp;
		} 
    }
    int jumpFloorII(int number) {
		
		if(number == 1){
			return 1;
		}
		else if(number == 2){
			return 2;
		}
		else{
			int temp = 0, count=3;
			for(int i=3; i<=number; i++){
				temp = 1 + count;
				count += temp;
			}
			return temp;
		}
    }
};


int main(){
	
	return 0;
}
