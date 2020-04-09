/*
һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж������������Ⱥ����ͬ�㲻ͬ�Ľ������
����˼·: 
�����ǰֻ����1��̨�ף���ʣ�»���f(n-1)�֣� �����������̨�� ��ʣ�»���f(n-2)�֣� 
���f(n) = f(n-1)+f(n-2) ��f(1)=1 f(2)=2����˸���������һ��쳲��������� 

��Ŀ�Ѷ�����: һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж�����������
����˼·��
��ʱû���������������� ��ôf(n) = f(0) + f(1) + ... + f(n-1) ��Ϊ��һ����n����ֻ��һ����ô�������
f(0) ����ֱ����n����ôֻ��һ����� =1 
f(1) = 1
f(2) =2
f(3) �ɷ�Ϊ f(0)+f(1)+f(2)= 1+1+2=4  
f(4) �ɷ�Ϊ f(0)+f(1)+f(2)+f(3) = 1+1+2+4=8
...
��f(n)����ǰ�����֮��+1 �ɵ������������ 
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
