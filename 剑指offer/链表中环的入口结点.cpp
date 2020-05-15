/*
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
*/

#include<iostream>
#include<map>

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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        map<ListNode*, int> m;
        m[NULL] = 0;
        ListNode* p = pHead;
        while(p!=NULL){
        	
        	if(m.count(p) == 0){
        		m[p] = 1;
			}
			else{
				break;
			}
        	p = p->next;
		}
		return p;
    }
    ListNode* EntryNodeOfLoop2(ListNode* pHead)
    {
        ListNode* fast=pHead, *slow = pHead;
        while(fast && fast->next){
        	fast = fast->next->next;
        	slow = slow->next;
        	if(fast == slow)
        		break;
		}
		//判断该链表是否存在环 
		if(fast==NULL || fast->next==NULL){
			return NULL;
		}
		//一个从相遇点继续走 一个从表头走 
		slow = pHead;
		while(slow!=fast){
			fast=fast->next;
			slow=slow->next;
		}
		return fast;
    }
}; 

int main(){
	ListNode* r1 = new ListNode(1);
	ListNode* r2 = new ListNode(2);
	ListNode* r3 = new ListNode(3);
	ListNode* r4 = new ListNode(4);
	ListNode* r5 = new ListNode(5);
	
	r1->next = r2;
	r2->next = r3;
	r3->next = r4;
	r4->next = r5;
	r5->next = r2;
	Solution s;
	ListNode* p = s.EntryNodeOfLoop2(r1);
	cout<<p->val;
	return 0;
	
}
