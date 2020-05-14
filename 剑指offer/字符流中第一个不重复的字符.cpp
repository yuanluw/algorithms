/*
请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，
第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
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

