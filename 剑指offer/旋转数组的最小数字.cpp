/*
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

解题思路:
根据旋转数组特性，考虑二分法来解决这个问题 mid = (left+right)/2
当a[left] = a[mid], 无法判断mid所处位置 如[2 2 1] [2 1 2 2 2] 
则令 left = left+1 
当a[left] > a[mid] ,意味着left在前半截有序数组中，mid在后半截有序数组中，而最小值是后半截有序数组的第一个元素 
则令 right = mid (不等于mid-1 是考虑a[mid]可能即为最小值)如 [6 7 1 2 3] 
当a[left] < a[mid], 意味着left和mid均在同一截有序数组中 如
则令 left = mid (不等于mid+1, 是为了避免a[mid+1]就是最小值 但是进入第一种情况 left=left+1 导致出错) 如[3 5 5 7 0 0 2]
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
