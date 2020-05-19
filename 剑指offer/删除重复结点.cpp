/*
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
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
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == NULL || pHead->next==NULL)
            return pHead;
        
        ListNode *newHead = new ListNode(-1);
        newHead->next = pHead;
        ListNode* pre=newHead;
        ListNode* next = NULL;
        ListNode* p = pHead;
        while(p!=NULL && p->next!=NULL){
            next = p->next;
            if(p->val == next->val){
                while(next != NULL && next->val == p->val){
                    next = next->next;
                }
                pre->next = next;
                p = next;
            }
            else{
                pre = p;
                p = p->next;
            }
        }
        return newHead->next;
    }
};


int main(){
	ListNode* r1 = new ListNode(1);
	ListNode* r2 = new ListNode(2);
	ListNode* r3 = new ListNode(3);
	ListNode* r4 = new ListNode(3);
	ListNode* r5 = new ListNode(4);
	ListNode* r6 = new ListNode(4);
	ListNode* r7 = new ListNode(5);
	r1->next = r2;
	r2->next = r3;
	r3->next = r4;
	r4->next = r5;
	r5->next = r6;
	r6->next = r7;
	
	Solution s;
	ListNode *temp = s.deleteDuplication(r1);
	while(temp!=NULL){
		cout<<temp->val<<" ";
		temp = temp->next;
	}
	
	
	
	return 0;
}
