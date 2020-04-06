/*
������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint����

����˼·:
- ��򵥵ľ���stack1���ڽ��ӣ� ����ʱ�Ƚ�stack1����ȫ������stack2�У���ʱstack2ջ�����Ƕ�����Ԫ�أ�Ȼ�������ν�stack2�����ͻ�stack1���ָ�ԭ��
- ��������ÿ��Ҫ�ָ�stack1̫�鷳����ʵ���Բ��ָ�stack1��ֻҪstack2�������ݣ����Ƕ�����Ԫ�أ��������Ӽ��� 
*/ 

#include<iostream>
#include<stack>

using namespace std;
 


class Solution
{
public:
    void push(int node) {
    	stack1.push(node);
    }

    int pop() {
    	if(stack1.empty() && stack2.empty()){
    		return 0; //ջ�� 
		}
		//stack2û�����ݣ���stack1�������δ��� 
		if(stack2.empty()){
			while(!stack1.empty()){
	        	stack2.push(stack1.top());
	        	stack1.pop();
			}
		}

    	int node = stack2.top();
		stack2.pop();
		return node;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main(){
	Solution s;
	
	s.push(1);
	s.push(2);
	cout<<s.pop()<<endl;
	s.push(3);
	s.push(4);
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	
	return 0;
	
	
	
	
}
