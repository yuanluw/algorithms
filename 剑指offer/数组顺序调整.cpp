/*
����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣�
���е�ż��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣
*/ 

#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
	//����1 
    void reOrderArray(vector<int> &array) {
        	
        int left=0;
        while(left < array.size()){
        	
        	//��ͷ�ҵ���һ��ż�� 
        	while(array[left]%2)
        		left++;
        	//���Ѱ�ҵ�һ������ 
        	int right = left+1; 
        	while((array[right]%2)==0 && right<array.size())
        		right++;
        	//�Ѿ��������������˳� 
        	if(right<array.size()){
        		int temp = array[right];
        		for(int i=right; i>left;i--){
        			array[i] = array[i-1];
				}
				array[left] = temp;
				left++;
			} 
        	else
        		break;
		}
        
    }
    //����2 
    void reOrderArray2(vector<int> &array){
    	vector<int> temp;
    	
    	for(vector<int>::iterator iter=array.begin(); iter!=array.end();){
    		if(*iter % 2 == 0){
    			temp.push_back(*iter);
    			array.erase(iter);
			}
			else
				iter++;
		}
		for(vector<int>::iterator iter=temp.begin(); iter!=temp.end(); iter++){
			array.push_back(*iter);
		}
	}
};


int main(){
	
	vector<int> a = {5,9,2,3,8,1,0,3,4};
	Solution s;
	
	s.reOrderArray2(a);
	
	for(vector<int>::iterator iter=a.begin(); iter!=a.end(); iter++){
		cout<<*iter<<endl;
	}
	
	return 0;
	
}
