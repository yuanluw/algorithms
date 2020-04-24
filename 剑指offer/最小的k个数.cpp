/*
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
解题思路:
这题考虑排序算法，找出前k个元素 可考虑堆排序或者快排
1 简单粗暴 使用快排排序后返回前k个元素
2 不需要对整个数组进行排序，按照快排的思想，每个固定一个元素的位置index， index前的元素均小于input[index] 后的元素则大于。
因此我们可根据固定的元素位置index来判断。 如果index=k 满足条件 index>k 则对input[0:index-1]再次划分 index<k 则对[index+1, end]再划分直至满足条件
3 使用优先队列, 优先队列(最大堆)只存储k个元素，后续元素只需跟队列头比较，小于队列头则替换
4 优先队列在插入元素调整的时候会保持整个堆的有序，但是我们只需要堆顶元素为当前堆最大元素即可，因此自己实现堆更新算法，只维持堆顶元素最大. 
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
    		//得到左右子树中大的那个元素 
			child = 2*pos + 1;
    		if(child<len && heap[child]<heap[child+1]){
    			child++;
			}
			//跟父结点比较 
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
