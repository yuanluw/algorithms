/* ����һ�������������β��ͷ��˳�򷵻�һ��ArrayList�� 
 
ʵ��˼·
1 ˳���������ͬʱʹ��һ��ջ��¼����
2 ʹ�õݹ�  ��˼·1���ƣ�Ҳ��ʹ����ջ 
3 ʹ������ָ����ת����ָ��, Ȼ����˳��������� ���ǻ��ƻ�ԭʼ���ݽṹ  
*/
#include<iostream>  
#include<stack>
#include<vector>  
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
	// �ⷨ1 
    vector<int> printListFromTailToHead(ListNode* head) {
        ListNode *p = head;
        stack<int> s;
        vector<int> v;
        
		while(p != NULL){
			s.push(p->val);
			p = p->next;
		}  
		while(!s.empty()){
			v.push_back(s.top());
			s.pop();
		}
		return v;
    }
    // �ⷨ2 
	vector<int> v;
    vector<int> printListFromTailToHead2(ListNode* head) {
        ListNode *p = head;
        
		if(p != NULL){
			printListFromTailToHead2(p->next); 	
			v.push_back(p->val);
		} 
		return v;
    }
    // �ⷨ3
	vector<int> printListFromTailToHead3(ListNode* head) {

		vector<int> v;
		if(head == NULL){
			return v;
		}
		if(head->next == NULL){
			v.push_back(head->val);
			return v;
		}
        ListNode *pre = head;
        ListNode *cur = pre->next;
        //��תָ�� 
        pre->next = NULL;
		while(cur->next != NULL){
			ListNode *next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		cur->next = pre;
        head = cur;
        ListNode *p = head;
		while(p != NULL){
			v.push_back(p->val);
			p = p->next;
		} 
		return v;
    }
};


int main(){
	
	ListNode *head = new ListNode(1);
	ListNode *p = head;
	for(int i=2; i<10; i++){
		ListNode *q = new ListNode(i);
		p->next = q;
		p = q; 
	} 
	Solution s;
	vector<int> result = s.printListFromTailToHead2(head);
	
	for(vector<int>:: iterator iter=result.begin(); iter!=result.end(); iter++){
		cout<<*iter<<endl;
	}
	return 0;
}
