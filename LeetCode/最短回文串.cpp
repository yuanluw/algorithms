#include<iostream>
#include<cstring>
#include<algorithm> 


using namespace std;


 class Solution {
public:
	
	void prefix_table(string s, int* &prefix, int n){
		
		prefix[0] = 0;
		
		int i=1, len=0;
		while(i<n){
			if(s[len] == s[i]){
				prefix[i++] = ++len;
			}
			else{
				if(len>0){
					len = prefix[len-1];
				}
				else{
					prefix[i] = len;
					i++;
				}
			}
		}
	}
	
    bool isPalindrome(string s, int start, int end){
        
        while(start < end){
            if(s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    string shortestPalindrome1(string s) {
        
        int len = s.length();
        if(len <= 1)
            return s;

        string result;
        for(int i=len-1;i>=0;i--){
            if(isPalindrome(s, 0, i)){
                string temp = s.substr(i+1, len);
                reverse(temp.begin(), temp.end());
                result = temp + s;
                return result;
            }
        }
    }
    
    string shortestPalindrome(string s){
    	int len = s.length();
        if(len <= 1)
            return s;
        string rev = s;
        reverse(rev.begin(), rev.end());
        if(rev == s)
        	return s;
		
		string catStr = s + '#' + rev;
        
        int n = catStr.length();
        int *prefix = new int[n];
        prefix_table(catStr, prefix, n);
        for(int i=0;i<n;i++){
        	cout<<prefix[i]<<endl;
		}
    	return rev + s.substr(prefix[n-1]);
	}
};


int main(){
	
	Solution s;
	cout<<s.shortestPalindrome("aacecaaa");
	
	return 0;
}
