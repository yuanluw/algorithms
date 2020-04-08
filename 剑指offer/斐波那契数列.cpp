/*
��Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n���0��ʼ����0��Ϊ0����n<=39

����˼·:
쳲��������м� F[n] = F(n-1) + F(n-2) f1 = f2 = 1
- ����ľ��ǵݹ�ķ����� ��������nԽ��Խ�� ������������
- ��̬�滮��˼�� ��һ�������¼��f(1)��ʼÿ������ֵ�����Ǳ���ֻҪ�������n���ֵ��ֻʹ������������¼f(n-1)��f(n-2)���� 
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
