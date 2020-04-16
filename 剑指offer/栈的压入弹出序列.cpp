/*
���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳��
����ѹ��ջ���������־�����ȡ���������1,2,3,4,5��ĳջ��ѹ��˳������4,5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У�
��4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С���ע�⣺���������еĳ�������ȵģ�
3 2 1 5 4
4,3,2 1, 5
����˼·:
1 ֱ��ģ����ջ���̣� ����ѹ������ÿ����ջһ��Ԫ�ء� ���ջ��Ԫ�ص��ڵ������е�ǰԪ�أ����Ԫ�س�ջ�� ���ֻ���жϸ�ջ�Ƿ�Ϊ�ռ���
2 ������ջ���������жϣ� ����pushA[0]�У� ƾ���Ԫ����popA������λ�ã����ɽ�popA��Ϊ������P1��P2 
��P1��Ԫ��һ���Ǳ�P2��Ԫ������ջ�ģ���Ӧ������Ҳ�ɰѳ�pushA[0]������з�Ϊ�����֣�ǰ�벿��������ջ�ġ�
���ݸ÷������ɽ��ж�εݹ�ָ� 
�˳�����������: ����Ϊ�ջ����������о�ֻʣһ��Ԫ����������ջ˳������  
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
			//�ҵ�pushV[0]��popV�ж�Ӧ��Ԫ��λ�� 
			int index=0;
			for(index=0;index<pushV.size();index++){
				if(pushV[0] == popV[index])
					break;	
			}
			vector<int> pre_pushV, post_pushV, pre_popV, post_popV;
			
			//���з�Ϊ������ 
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
