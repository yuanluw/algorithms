/*
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
解题思路:
这个题目真正要处理的地方就是random指针，random指针随机指向某个结点，因此我们需要知道复制结点和原结点的对应位置 
方法1 
	先进行复制将 A->B->C 变为 A->A'->B->B'->C->C', 此时我们就知道random指针指向的结点的下一个即是它的复制结点  
	复制random指针 即newHead->random = pHead->random.next
	拆分为两个结点
方法2
	直接复制出第二条链表，同时使用map去记录原结点和复制结点的对应关系
	根据map来更新复制结点的random指针  newHead->random = map[pHead->random] 
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
		
		//将A->B->C 变为 A->A'->B->B'->C->C' 
		while(p){
			q->next = p->next;
			p->next = q;
			
			p = p->next->next;
			if(p)
				q = new RandomListNode(p->label); 
			else
				q = NULL;
		}
		//更新random指针
		p = pHead, q=p->next;
		while(p){
			//p->random->next即为随机结点对应的复制结点位置
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
		
		//拆分成两个链表
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
		//存在random结点为NULL的情况 
		headMap[NULL] = NULL;
		//复制一份结点 同时记录原结点和复制结点的对应关系
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
