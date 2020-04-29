/*
统计一个数字在排序数组中出现的次数。
解题思路:
1 直接for暴力解题
2 因为为排序数组，因此考虑二分查找 
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
	int GetNumberOfK(vector<int> data ,int k) {
        
        if(data.size() == 0)
        	return 0;
        //找到k所处位置 
        int index = findNumber2(data, k, 0, data.size()-1);
        //查找失败 
        if(index == -1)
        	return 0;
        //统计前后位置k的个数 
        int cnt = 1;
		int temp = index-1;
		while(temp >= 0)
            if(data[temp--] == k)
                cnt++;
        temp = index+1;
        while(temp < data.size())
            if(data[temp++] == k)
                cnt++;
        return cnt;
        
    }
    //二分查找 递归版 
    int findNumber(vector<int> data, int k, int start, int end){
    	
    	int mid = (end+start)/2;
		
		if(start<=end){
			if(data[mid] == k)
				return mid;
			else if(data[mid] > k){
				end = mid-1;
				return findNumber(data, k, start, end);
			}
			else if(data[mid] < k){
				start = mid+1;
				return findNumber(data, k, start, end);
			}
		}
		return -1;
	}
	//二分查找 迭代版 
	int findNumber2(vector<int> data, int k, int start, int end){
		int mid;
		while(start<=end){
			mid = (end+start)/2;
			if(data[mid] == k)
				return mid;
			else if(data[mid] > k){
				end = mid-1;
			}
			else if(data[mid] < k){
				start = mid+1;
			}
		}
		return -1;
	}
};


int main(){
	
	vector<int> data = {1, 3, 5, 6};
	Solution s;
	
	cout<<s.GetNumberOfK(data, 6)<<endl;
	return 0;
}
