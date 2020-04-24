/*
����n���������ҳ�������С��K��������������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4,��
����˼·:
���⿼�������㷨���ҳ�ǰk��Ԫ�� �ɿ��Ƕ�������߿���
1 �򵥴ֱ� ʹ�ÿ�������󷵻�ǰk��Ԫ��
2 ����Ҫ����������������򣬰��տ��ŵ�˼�룬ÿ���̶�һ��Ԫ�ص�λ��index�� indexǰ��Ԫ�ؾ�С��input[index] ���Ԫ������ڡ�
������ǿɸ��ݹ̶���Ԫ��λ��index���жϡ� ���index=k �������� index>k ���input[0:index-1]�ٴλ��� index<k ���[index+1, end]�ٻ���ֱ����������
3 ʹ�����ȶ���, ���ȶ���(����)ֻ�洢k��Ԫ�أ�����Ԫ��ֻ�������ͷ�Ƚϣ�С�ڶ���ͷ���滻
4 ���ȶ����ڲ���Ԫ�ص�����ʱ��ᱣ�������ѵ����򣬵�������ֻ��Ҫ�Ѷ�Ԫ��Ϊ��ǰ�����Ԫ�ؼ��ɣ�����Լ�ʵ�ֶѸ����㷨��ֻά�ֶѶ�Ԫ�����. 
*/ 

#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h> 

using namespace std;


class Solution{
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
     	priority_queue<int> q;
     	vector<int> res;
     	if(input.size() < k || k <= 0)
     		return res;
     	
     	for(int i=0;i<input.size();i++){
     		if(q.size() < k)
     			q.push(input[i]);
     		else if(input[i] < q.top()){
     			q.pop();
     			q.push(input[i]);
			 }
		 }
		 while(!q.empty()){
		 	res.push_back(q.top());
		 	q.pop();
		 }
		 return res;
    }
    
    vector<int> GetLeastNumbers_Solution2(vector<int> input, int k) {
    	
    	vector<int> res;
    	if(input.size() < k || k <= 0)
     		return res;
     		
     	int temp;
     	int *heap = new int[k](); 
     	for(int i=0;i<input.size();i++){
			if(i < k){
				heap[i] = input[i];
	 			temp = heap[0];
	 			heap[0] = heap[i];
	 			heap[i] = temp;
	 			adjustHeap(heap, 0, i+1);
			}
			else if(input[i] < heap[0]){
					temp = input[i];
		 			heap[0] = heap[k-1];
		 			heap[k-1] = temp;
		 			adjustHeap(heap, 0, k);
			}
			
		}
		for(int i=0;i<k;i++){
			res.push_back(heap[i]);
		}
		return res;	
    }
    
    void adjustHeap(int heap[], int pos, int len){
    	
    	int temp, child;
    	for(temp=heap[pos];pos*2+1<=len;pos=child){
    		//�õ����������д���Ǹ�Ԫ�� 
			child = 2*pos + 1;
    		if(child<len && heap[child]<heap[child+1]){
    			child++;
			}
			//�������Ƚ� 
			if(heap[child]>temp){
				heap[pos] = heap[child];
			}
			else
				break;
		}
		heap[pos] = temp; 
	}
	
	int getPartition(vector<int> &input, int start, int end){
		if(input.empty() || start>end)
			return -1;
		int temp = input[start];
		int i = start, j = end;
		while(i<j){
			while(i<j && input[j]>=temp)
				j--;
			if(i<j)
				input[i++] = input[j];
			while(i<j && input[i]<temp)
				i++;
			if(i<j)
				input[j--] = input[i];
		
		}
		input[i] = temp;
		return i; 
	}
	
	vector<int> GetLeastNumbers_Solution3(vector<int> input, int k){
		vector<int> res;
    	if(input.size() < k || k <= 0)
     		return res;
     	
     	int start = 0, end=input.size()-1;
     	int index = getPartition(input, start, end);
		while(index != (k-1)){
			if(index > (k-1))
				end = index - 1;
			else
				start = index + 1;
			index = getPartition(input, start, end);
		}
		for(int i=0;i<k;i++)
			res.push_back(input[i]);
		
		return res;
	}
}; 


int main(){
	
	vector<int> input = {4,5,1,6,2,7,3,8};
	Solution s;
	
	vector<int> res = s.GetLeastNumbers_Solution3(input, 5);
	
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<endl;
	}
	
	return 0;
}
