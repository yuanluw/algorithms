/*
LL���������ر��,��Ϊ��ȥ����һ���˿���,���������Ȼ��2������,2��С��(һ����ԭ����54��^_^)...
��������г����5����,�����Լ�������,�����ܲ��ܳ鵽˳��,����鵽�Ļ�,������ȥ��������Ʊ,�ٺ٣�����
����A,����3,С��,����,��Ƭ5��,��Oh My God!������˳��.....LL��������,��������,������\С �����Կ����κ�����,��
��A����1,JΪ11,QΪ12,KΪ13�������5���ƾͿ��Ա�ɡ�1,2,3,4,5��(��С���ֱ���2��4),��So Lucky!����
LL����ȥ��������Ʊ���� ����,Ҫ����ʹ�������ģ������Ĺ���,Ȼ���������LL��������Σ� ����������˳�Ӿ����true��
��������false��Ϊ�˷������,�������Ϊ��С����0��
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size() != 5)
            return false;
        int jokerCnt = 0, min=14, max=-1;
        int *d = new int[14]();
        //����5�����Ƶ����
        d[0] = -5;
        for(int i=0;i<numbers.size();i++){
            d[numbers[i]]++;
            if(d[numbers[i]] > 1)
                return false;
            if(numbers[i] == 0)
            	continue;
            if(numbers[i] > max)
                max = numbers[i];
            if(numbers[i] < min)
                min = numbers[i];
        }
        
        if(max-min < 5){
            return true;
        }
        return false;
    }
};


int main(){
	
	vector<int> data = {0,3,2,6,4};
	Solution s;
	cout<<s.IsContinuous(data);
	return 0;
}
 
