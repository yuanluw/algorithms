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
            //���� 
            while(temp--){
                //ÿ��ǰ��һ����Ч��� 
				index = (index+1)%n;
				while(d[index] == 1)
                    index = (index+1)%n;
            }
			//��־�ý���Ѿ���Ч 
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
