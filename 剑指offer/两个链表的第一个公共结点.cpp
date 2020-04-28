/*
输入两个链表，找出它们的第一个公共结点。（注意因为传入数据是链表，所以错误测试数据的提示是用其他方式显示的，保证传入数据是正确的）
解题思路:
因为两个链表是单链表，因此找到第一个公共结点后序结点都一样了 
1 找到两个链表长度得到长度差len，让长链表先走len步， 此时即可同时移动两个链表指针，要么两者相同则得到第一个公共结点，要么均为NULL退出循环
2 无需链表长度, 用两个指针分别指向两个链表头,让它们同步移动，如果走到了NULL则继续从另外一个链表头走起，如果两个链表存在公共结点，
那么两个指针一定能相遇，或者同时走到null退出循环 
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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        
        if(pHead1 == NULL || pHead2 == NULL)
        	return NULL;
        //获得长度 
        int len1 = getListLen(pHead1);
        int len2 = getListLen(pHead2);
        ListNode *p = pHead1, *q = pHead2;
        //长链表先走abs(len1-len2)步 
		if(len1 > len2){
        	p = walkStep(p, len1-len2);
		}
		else{
			q = walkStep(q, len2-len1);
		}
		//同步移动两个链表指针 
		while(p!=NULL){
			if(p == q)
				return p;
			p = p->next;
			q = q->next;
		}
        return NULL;
        
    }
    
    int getListLen(ListNode* head){
         if(head == NULL) return 0;
            int sum = 1;
            while(head = head->next) sum++;
            return sum;
    } 
    
	ListNode* walkStep(ListNode* head, int step){
		while(step--){
			head = head->next;
		}
		return head;
	}
};

int main(){
	
	ListNode* root = new ListNode(1);
	ListNode* root2 = new ListNode(2);
	
	ListNode* root3 = new ListNode(3);
	ListNode* root4 = new ListNode(4);
	
	ListNode* root5 = new ListNode(5);
	
	root->next = root3;
	root2->next = root4;
	root3->next = root5;
	root4->next = root5;
	
	Solution s;
	ListNode* result = s.FindFirstCommonNode(root, root2);
	if(result == NULL)
		cout<<" "<<endl;
	else
		cout<<result->val<<endl; 
	return 0;
	
}
