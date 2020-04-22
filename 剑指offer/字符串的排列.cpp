/*
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,
则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。长度不超过9(可能有字符重复),字符只包括大小写字母。 
解题思路:
1 每次固定一个元素，然后递归暴力求解 
2 全排列 
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	void per(string str, vector<char> &table, int index, bool *dp, vector<string> &s){
		
		if(index == str.size()){
			string strTem;
			strTem.assign(table.begin(), table.end());
			s.push_back(strTem);
		}
		else{
			for(int i=0;i<str.size();i++){
				if(!dp[i]){
					dp[i] = true;
					table.push_back(str[i]);
					per(str, table, index+1, dp, s);
					table.pop_back();
					dp[i] = false;
				}
			}
		}
		
	}
	
    vector<string> Permutation(string str) {
        
        vector<string> vec;
        if(str == "")
        	return vec;
        
		bool* dp = new bool[str.size()] { 0 };
        vector<char> table;
        per(str, table, 0, dp, vec);
		sort(vec.begin(), vec.end());
		vec.erase(unique(vec.begin(), vec.end()), vec.end());
        return vec;
    }
    
    vector<string> Permutation2(string str){
    	
    	vector<string> vec;
    	if(str == "")
    		return vec;
    	per2(str, 0,  vec);
		sort(vec.begin(), vec.end());
		vec.erase(unique(vec.begin(), vec.end()), vec.end());
        return vec;
	}
	
	void per2(string str, int index, vector<string> &vec){
		if(index == str.size()){
			vec.push_back(str);
		}
		else{
			for(int i=index; i<str.size(); i++){
				swap(str[i], str[index]);
				per2(str, index+1, vec);
				swap(str[i], str[index]);
			}
		} 
	}
	
	void swap(char &c1, char &c2){
		char temp = c1;
		c1 = c2;
		c2 = temp;
	}

};


int main(){
	
	string str = "abcdefeds";
	Solution s;
	vector<string> vec = s.Permutation2(str); 
	cout<<vec.size();
	return 0;
} 
