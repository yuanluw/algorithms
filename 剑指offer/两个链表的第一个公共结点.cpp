/*
�������������ҳ����ǵĵ�һ��������㡣��ע����Ϊ�����������������Դ���������ݵ���ʾ����������ʽ��ʾ�ģ���֤������������ȷ�ģ�
����˼·:
��Ϊ���������ǵ���������ҵ���һ�������������㶼һ���� 
1 �ҵ����������ȵõ����Ȳ�len���ó���������len���� ��ʱ����ͬʱ�ƶ���������ָ�룬Ҫô������ͬ��õ���һ��������㣬Ҫô��ΪNULL�˳�ѭ��
2 ����������, ������ָ��ֱ�ָ����������ͷ,������ͬ���ƶ�������ߵ���NULL�����������һ������ͷ�����������������ڹ�����㣬
��ô����ָ��һ��������������ͬʱ�ߵ�null�˳�ѭ�� 
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
        //��ó��� 
        int len1 = getListLen(pHead1);
        int len2 = getListLen(pHead2);
        ListNode *p = pHead1, *q = pHead2;
        //����������abs(len1-len2)�� 
		if(len1 > len2){
        	p = walkStep(p, len1-len2);
		}
		else{
			q = walkStep(q, len2-len1);
		}
		//ͬ���ƶ���������ָ�� 
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
