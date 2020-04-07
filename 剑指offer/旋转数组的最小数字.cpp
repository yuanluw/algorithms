/*
��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء�
��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1��
NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��

����˼·:
������ת�������ԣ����Ƕ��ַ������������� mid = (left+right)/2
��a[left] = a[mid], �޷��ж�mid����λ�� ��[2 2 1] [2 1 2 2 2] 
���� left = left+1 
��a[left] > a[mid] ,��ζ��left��ǰ������������У�mid�ں������������У�����Сֵ�Ǻ�����������ĵ�һ��Ԫ�� 
���� right = mid (������mid-1 �ǿ���a[mid]���ܼ�Ϊ��Сֵ)�� [6 7 1 2 3] 
��a[left] < a[mid], ��ζ��left��mid����ͬһ������������ ��
���� left = mid (������mid+1, ��Ϊ�˱���a[mid+1]������Сֵ ���ǽ����һ����� left=left+1 ���³���) ��[3 5 5 7 0 0 2]
*/ 

#include<iostream>
#include<vector>

using namespace std; 


class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size() == 0)
    		return 0;
    	int left=0, right=rotateArray.size()-1;
    	while(left<right){
    		int mid = (right+left)/2;
    		if(rotateArray[left]>rotateArray[mid])
    			right = mid;
    		else if(rotateArray[left] < rotateArray[mid])
    			left = mid;
    		else
    			left = left+1;
			 
		}
		return rotateArray[left];
    }
};


int main(){
	
	vector<int> a = {3, 5, 5, 7, 0, 0, 2};
	Solution s;
	cout<<s.minNumberInRotateArray(a);
	
	return 0;
}
