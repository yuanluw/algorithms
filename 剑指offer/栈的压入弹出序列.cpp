/*
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
3 2 1 5 4
4,3,2 1, 5
解题思路:
1 直接模拟入栈过程， 根据压入序列每次入栈一个元素。 如果栈顶元素等于弹出序列当前元素，则该元素出栈， 最后只需判断该栈是否为空即可
2 根据入栈的特性来判断， 对于pushA[0]中， 凭借该元素在popA中所处位置，即可将popA分为两部分P1和P2 
且P1中元素一定是比P2中元素先入栈的，对应的我们也可把除pushA[0]外的序列分为两部分，前半部分是先入栈的。
根据该分析即可进行多次递归分割 
退出条件有两个: 序列为空或者两个序列均只剩一个元素且相等则出栈顺序正常  
*/ 

#include<iostream>
#include<stack>
#include<vector>

using namespace std;


class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size() == 0){
            return true;
        }
        stack<int> s;
        for(int i=0,j=0; i<pushV.size();i++){
            s.push(pushV[i]);
            while(j<popV.size() && popV[j] == s.top()){
                j++;
                s.pop();
            }
        }
        return s.empty();
    }
    
    bool IsPopOrder2(vector<int> pushV, vector<int> popV){
    	
    	if(pushV.size() == 0){
    		return true;
		}
		else if(pushV.size() == 1){
			return pushV[0] == popV[0];
		}
		else{
			//找到pushV[0]在popV中对应的元素位置 
			int index=0;
			for(index=0;index<pushV.size();index++){
				if(pushV[0] == popV[index])
					break;	
			}
			vector<int> pre_pushV, post_pushV, pre_popV, post_popV;
			
			//序列分为两部分 
			for(int i=0;i<index;i++)
				pre_pushV.push_back(pushV[i+1]);
			for(int i=index+1;i<pushV.size();i++)
				post_pushV.push_back(pushV[i]);
			for(int i=0;i<index;i++)
				pre_popV.push_back(popV[i]);
			for(int i=index+1;i<popV.size();i++)
				post_popV.push_back(popV[i]);
			return IsPopOrder2(pre_pushV, pre_popV) && IsPopOrder2(post_pushV, post_popV);
			
		}
    	
	} 
    
    
};


int main(){
	
	vector<int> pushA = {1, 2}, popA = {2, 1};
	
	Solution s;
	
	cout<<s.IsPopOrder2(pushA, popA);
	
	return 0;
}
