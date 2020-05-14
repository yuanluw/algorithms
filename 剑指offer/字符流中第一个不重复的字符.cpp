/*
��ʵ��һ�����������ҳ��ַ����е�һ��ֻ����һ�ε��ַ������磬�����ַ�����ֻ����ǰ�����ַ�"go"ʱ��
��һ��ֻ����һ�ε��ַ���"g"�����Ӹ��ַ����ж���ǰ�����ַ���google"ʱ����һ��ֻ����һ�ε��ַ���"l"��
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Solution
{
public:
    //Insert one char from stringstream
    void Insert(char ch)
    {
    	v.push_back(ch);
		m[ch] ++;

        return ;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
    	for(int i=0;i<v.size();i++)
    		if(m[v[i]] == 1)
    			return v[i];
    	return '#';
    }
private:
	int *m =new int[256]();
    vector<char> v;

};



int main(){
	
	Solution s;
	s.Insert('B');
	cout<<s.FirstAppearingOnce()<<endl;
	s.Insert('a');
	cout<<s.FirstAppearingOnce()<<endl;
	s.Insert('b');
	cout<<s.FirstAppearingOnce()<<endl;
	s.Insert('y');
	cout<<s.FirstAppearingOnce()<<endl;
	s.Insert('B');
	cout<<s.FirstAppearingOnce()<<endl;
	s.Insert('a');
	cout<<s.FirstAppearingOnce()<<endl;
	return 0;
}

