/*
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007
解题思路:
1 暴力求解法 两轮for循环
2 利用归并排序的思想 
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
        //开辟临时数组用于归并排序 
        int* copy=new int[data.size()]();
		int count = Inverse(data, copy, 0, data.size()-1);
        delete[] copy;
		return count;
    }

	 int Inverse(vector<int>& data,int*& copy,int start,int end)
	{
        if(start==end)
            return 0;

        //将数组拆分成两部分
        int length=(end-start)/2;
        //分别计算左边部分和右边部分
        int left=Inverse(data,copy,start,start+length)%1000000007;
        int right=Inverse(data,copy,start+length+1,end)%1000000007;
        //进行逆序计算
        int i=start+length;//前一个数组的最后一个下标
        int j=end;//后一个数组的最后一个下标
        int index=end;
        int count=0;
        while(i>=start && j>=start+length+1)
        {
            if(data[i]>data[j])
            {
                copy[index--]=data[i--];
                //统计长度
                count+=j-start-length;
                if(count>=1000000007)//数值过大求余
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
        //排序
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
