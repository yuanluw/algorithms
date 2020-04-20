/*
����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬��һ������ָ��ָ������һ���ڵ㣩��
���ؽ��Ϊ���ƺ��������head����ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�
����˼·:
�����Ŀ����Ҫ����ĵط�����randomָ�룬randomָ�����ָ��ĳ����㣬���������Ҫ֪�����ƽ���ԭ���Ķ�Ӧλ�� 
����1 
	�Ƚ��и��ƽ� A->B->C ��Ϊ A->A'->B->B'->C->C', ��ʱ���Ǿ�֪��randomָ��ָ��Ľ�����һ���������ĸ��ƽ��  
	����randomָ�� ��newHead->random = pHead->random.next
	���Ϊ�������
����2
	ֱ�Ӹ��Ƴ��ڶ�������ͬʱʹ��mapȥ��¼ԭ���͸��ƽ��Ķ�Ӧ��ϵ
	����map�����¸��ƽ���randomָ��  newHead->random = map[pHead->random] 
*/ 


#include<iostream>
#include<vector>
#include<map> 

using namespace std;


struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead){
		
		if(pHead == NULL)
			return NULL;
		
		RandomListNode *cloneHead = new RandomListNode(pHead->label);
		RandomListNode *p = pHead, *q = cloneHead;
		
		//��A->B->C ��Ϊ A->A'->B->B'->C->C' 
		while(p){
			q->next = p->next;
			p->next = q;
			
			p = p->next->next;
			if(p)
				q = new RandomListNode(p->label); 
			else
				q = NULL;
		}
		//����randomָ��
		p = pHead, q=p->next;
		while(p){
			//p->random->next��Ϊ�������Ӧ�ĸ��ƽ��λ��
			if(p->random)	 
				q->random = p->random->next;
			else
				q->random = NULL; 
			p = q->next;
			if(p)
				q = p->next;
			else
				q = NULL; 
		} 
		
		//��ֳ���������
		p = pHead, q = cloneHead;
		while(p){
			p->next = q->next;
			if(p->next) 
				q->next = p->next->next;
			else
				q->next = NULL;
			
			p = p->next;
			q = q->next;
		} 
		
		return cloneHead;
    }

	RandomListNode* Clone2(RandomListNode* pHead){
		if(pHead == NULL)
			return NULL;
		
		RandomListNode *cloneHead = new RandomListNode(pHead->label);
		RandomListNode *p = pHead, *q = cloneHead;
		map<RandomListNode*, RandomListNode*> headMap;
		//����random���ΪNULL����� 
		headMap[NULL] = NULL;
		//����һ�ݽ�� ͬʱ��¼ԭ���͸��ƽ��Ķ�Ӧ��ϵ
		headMap[p] = q; 
		while(p){
			p = p->next;
			
			if(p){
				RandomListNode *new_node = new RandomListNode(p->label);
				q->next = new_node;
				q = q->next;
				headMap[p] = q;
			}
			else
				q->next = NULL;
		}
		
		p = pHead, q = cloneHead;
		while(p){
			q->random = headMap[p->random];
			q = q->next;
			p = p->next;
		} 
		
		return cloneHead;
	}
}; 


int main(){
	
	RandomListNode *root = new RandomListNode(1);
	RandomListNode *p2 = new RandomListNode(11);
	RandomListNode *p3 = new RandomListNode(12);
	
	root->next = p2;
	p2->next = p3;
	
	root->random = p3;
	p3->random = root;
	
	Solution s;
	
	RandomListNode *copyHead = s.Clone2(root);
	
	RandomListNode *p = copyHead;
	while(p){
	 	cout<<p->label<<" ";
		if(p->random)
			cout<<p->random->label<<endl;
		else
			cout<<endl; 
		p = p->next;
	} 
	return 0; 
	
	
}
