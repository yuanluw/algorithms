/*
HZż������Щרҵ������������Щ�Ǽ����רҵ��ͬѧ����������鿪����,���ַ�����:
�ڹ��ϵ�һάģʽʶ����,������Ҫ��������������������,������ȫΪ������ʱ��,����ܺý����
����,��������а�������,�Ƿ�Ӧ�ð���ĳ������,�������Աߵ��������ֲ����أ�����:{6,-3,-2,7,-15,1,2,2},��
��������������Ϊ8(�ӵ�0����ʼ,����3��Ϊֹ)����һ�����飬��������������������еĺͣ���᲻�ᱻ������ס��(�������ĳ���������1)

*/

#include<iostream>
#include<vector>

using namespace std;

class Solution{
	
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		
		if(array.size() == 0)
			return 0;
		
		int max=0x80000000; //int����Сֵ 
		int temp = 0;
		for(int i=0; i<array.size(); i++){
			temp += array[i];
			
			//��ǰֵ����max�� ���� 
			if(temp > max)
				max = temp;
			
			if(temp<0)
				temp = 0;
		}
		return max;
	}
};

int main(){
	
	vector<int> array = {1,-2,3,10,-4,7,2,-5};
	
	Solution s;
	cout<<s.FindGreatestSumOfSubArray(array);
	
	return 0;
	
}
