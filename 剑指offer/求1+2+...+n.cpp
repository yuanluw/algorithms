/*
��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����
����˼·
1 ֱ�Ӵ�1�ӵ�n�����ǵ�����ʹ��ѭ��������õݹ���ʵ�� 
�ݹ��˳�����Ϊn==0�� �����������������ʵ��
2 sum(1, n) = (n * n-1)/2, a*b��������λ������ʵ�� ��a=2�� b=5(������Ϊ101) ��a*b = a<<3 + a<<1  
*/

#include<iostream>

using namespace std;


class Solution {
public:
    int Sum_Solution(int n) {
        //�� n����0ʱ && ������򼴵ݹ鲻����ִ�� 
        n && (n += Sum_Solution(n-1));
        return n;
    }
    
    int Sum_Solution2(int n){
		//>>1�����2 
    	return mul(n, n+1)>>1;
	}
	
	int mul(int a, int b){
		int res = 0;
		//�ж�b�����λ�Ƿ�Ϊ0  
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

