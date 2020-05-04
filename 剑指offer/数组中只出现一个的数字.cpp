/*
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
解题思路
1. 开一个辅助数组存储每个元素出现次数
2. 考虑异或思想，两个相同的数字异或为0；
	第一次遍历数组，存储所有元素异或的结果。因为存在两个只出现一次的数，即他们的异或结果一定不为0，一定有一个位上有1。
	根据这一个不为1的位，我们可以把数组分为两部分，一部分即该位为1的元素，另一部分则相反
	对这两部分数组再进行第二次异或遍历，即可得到两个只出现一个的元素 
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
        //第一次异或遍历
        for(int i = 0 ; i < data.size(); ++ i )
            myxor ^= data[i];
        //找到两个只出现一个的元素不同的位
        while((myxor & flag) == 0) flag <<= 1;
        *num1 = myxor;
        *num2 = myxor;
        //第二次异或遍历
        for(int i = 0; i < data.size(); ++ i ){
            if((flag & data[i]) == 0) *num2 ^= data[i];
            else *num1 ^= data[i];
        }
    }
};
