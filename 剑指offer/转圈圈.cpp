/*

*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n == 0)
            return -1;
        int *d = new int[n]();
        int childCnt = n;
        int index = 0;
        while(childCnt > 1){
            int temp = m-1;
            //报号 
            while(temp--){
                //每次前进一个有效结点 
				index = (index+1)%n;
				while(d[index] == 1)
                    index = (index+1)%n;
            }
			//标志该结点已经无效 
            d[index] = 1; 
            while(d[index] == 1)
                index = (index+1)%n;
            childCnt--;
        }
        return index;
    }
    
    int LastRemaining_Solution2(int n, int m){
    	
	}
}; 


int main(){
	
	Solution s;
	cout<<s.LastRemaining_Solution(5, 2);
	return 0; 
}
