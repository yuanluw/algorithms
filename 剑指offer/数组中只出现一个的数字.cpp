/*
һ�����������������������֮�⣬���������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε����֡�
����˼·
1. ��һ����������洢ÿ��Ԫ�س��ִ���
2. �������˼�룬������ͬ���������Ϊ0��
	��һ�α������飬�洢����Ԫ�����Ľ������Ϊ��������ֻ����һ�ε����������ǵ������һ����Ϊ0��һ����һ��λ����1��
	������һ����Ϊ1��λ�����ǿ��԰������Ϊ�����֣�һ���ּ���λΪ1��Ԫ�أ���һ�������෴
	���������������ٽ��еڶ��������������ɵõ�����ֻ����һ����Ԫ�� 
*/ 

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size() < 2) 
            return ;
        int myxor = 0;
        int flag = 1;
        //��һ��������
        for(int i = 0 ; i < data.size(); ++ i )
            myxor ^= data[i];
        //�ҵ�����ֻ����һ����Ԫ�ز�ͬ��λ
        while((myxor & flag) == 0) flag <<= 1;
        *num1 = myxor;
        *num2 = myxor;
        //�ڶ���������
        for(int i = 0; i < data.size(); ++ i ){
            if((flag & data[i]) == 0) *num2 ^= data[i];
            else *num1 ^= data[i];
        }
    }
};
