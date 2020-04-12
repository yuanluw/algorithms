/*
����һ����������������е�����k����㡣
����˼·:
��������ָ�� ��һ��ָ�����ƶ�k����㣬Ȼ�����������ͬ���ƶ�����ָ��1��������βʱ��ָ��2ָ��ľ��ǵ�����k����� 
*/ 

#include<iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    	//������ 
    	if(pListHead == NULL || k < 0){
    		return NULL;
		}
    	ListNode* p = pListHead;
    	//ָ��1���ƶ�k��λ�� 
    	int i=0; 
    	while(p!=NULL && i!=k){
    		p = p->next;
    		i++;
		}
		//��������պ�ֻ��k������ ��������ڵ� 
		if(i == k && p == NULL){
			return pListHead;
		}
		//����������k����� 
		else if(p == NULL){
			return NULL;
		}
		//����ָ��ͬ���ƶ� 
		ListNode* q = pListHead;
		while(p!=NULL){
			p = p->next;
			q = q->next; 
		}
		
		return q;
    }
};


int main(){
	ListNode *root = new ListNode(1);
	ListNode *q = root;
	for(int i=2; i<10; i++){
		ListNode *new_data = new ListNode(i);
		q->next = new_data;
		q = new_data; 
	}
	Solution s;
	q = s.FindKthToTail(root, 8);
	cout<<q->val;
	
	return 0;
}
