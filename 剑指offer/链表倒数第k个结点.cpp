/*
输入一个链表，输出该链表中倒数第k个结点。
解题思路:
设置两个指针 第一个指针先移动k个结点，然后两个结点再同步移动，当指针1到底链表尾时，指针2指向的就是倒数第k个结点 
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
    	//输入检测 
    	if(pListHead == NULL || k < 0){
    		return NULL;
		}
    	ListNode* p = pListHead;
    	//指针1先移动k个位置 
    	int i=0; 
    	while(p!=NULL && i!=k){
    		p = p->next;
    		i++;
		}
		//整个链表刚好只有k个数据 则输出根节点 
		if(i == k && p == NULL){
			return pListHead;
		}
		//整个链表不足k个结点 
		else if(p == NULL){
			return NULL;
		}
		//两个指针同步移动 
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
