/*
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型

解题思路:
- 最简单的就是stack1用于进队， 出队时先将stack1数据全部放入stack2中，此时stack2栈顶就是队列首元素，然后再依次将stack2数据送回stack1，恢复原样
- 上述方法每次要恢复stack1太麻烦，其实可以不恢复stack1，只要stack2还有数据，即是队列首元素，继续出队即可 
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
    		return 0; //栈空 
		}
		//stack2没有数据，则将stack1数据依次存入 
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
