/*
�������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�
����һ������,�����������е�����Ե�����P������P��1000000007ȡģ�Ľ������� �����P%1000000007
����˼·:
1 ������ⷨ ����forѭ��
2 ���ù鲢�����˼�� 
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;


class Solution {
public:
    int InversePairs(vector<int> data) {
        if(data.size() <= 1)
        	return 0;
        //������ʱ�������ڹ鲢���� 
        int* copy=new int[data.size()]();
		int count = Inverse(data, copy, 0, data.size()-1);
        delete[] copy;
		return count;
    }

	 int Inverse(vector<int>& data,int*& copy,int start,int end)
	{
        if(start==end)
            return 0;

        //�������ֳ�������
        int length=(end-start)/2;
        //�ֱ������߲��ֺ��ұ߲���
        int left=Inverse(data,copy,start,start+length)%1000000007;
        int right=Inverse(data,copy,start+length+1,end)%1000000007;
        //�����������
        int i=start+length;//ǰһ����������һ���±�
        int j=end;//��һ����������һ���±�
        int index=end;
        int count=0;
        while(i>=start && j>=start+length+1)
        {
            if(data[i]>data[j])
            {
                copy[index--]=data[i--];
                //ͳ�Ƴ���
                count+=j-start-length;
                if(count>=1000000007)//��ֵ��������
                    count%=1000000007;
            }
            else
            {
                copy[index--]=data[j--];
            }
        }
        for(;i>=start;--i)
        {
            copy[index--]=data[i];
        }
        for(;j>=start+length+1;--j)
        {
            copy[index--]=data[j];
        }
        //����
        for(int i=start; i<=end; i++) {
            data[i] = copy[i];
        }
        return (count+left+right)%1000000007;
	}
};


int main(){
	
	vector<int> data = {1,2,3,4,5,6,7,0};
	
	Solution s;
	cout<<s.InversePairs(data);
	return 0;
}
