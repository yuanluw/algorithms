/*
����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��

����˼·:
����n=5:  0000 0000 0000 0000 0000 0000 0000 0000 0101   0110 1010  
    n=-5: 1111 1111 1111 1111 1111 1111 1111 1111 1011(ȡ����1) 
�ⷨ1: ��һ����־λ��n��ÿһλ�������������, ÿ���޸ı�־λ 
�ⷨ2:  �޸�����n ��ÿ������һλ�����ж�n�����λ�Ƿ�Ϊ0 ��Ϊ0���1 ��ֱ�����ƶ��ڸ������������
		��Ϊ�Ը����������������Ǹ�λ��1������������ѭ���� ���޸�n������Ϊunsigned�ͻ���ʹ��>>>(�޷�������)����ʱ����Ϊ�߼����� ����������ѭ�� 
�ⷨ3: Ҳ���޸�����n������ n=(n-1)&n�ķ�ʽ����λ��n=(n-1)&n��ʵ��ÿ�ν�n���ұߵĵ�һ��1��Ϊ0�Ĺ��ܣ���
	   ��ִ�ж��ٴθ�ʽ�������ж��ٸ�1 

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
