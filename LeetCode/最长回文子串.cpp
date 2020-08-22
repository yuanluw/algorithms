#include<iostream>
#include<string>
#include<vector>

using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        
        int len = s.size();
        if(len<2)
            return s;

        bool **dp = new bool*[len];
        for(int i=0;i<len;i++){
            dp[i] = new bool[len];
        }
        for(int i=0;i<len;i++)
            dp[i][i] = true;


        int maxLen = 1;
        int begin=0;
        for(int j=1;j<len;j++){
            for(int i=0;i<j;i++){
                if(s[i] != s[j]){
                    dp[i][j] = false;
                }
                else{
                    if(j-i<3){
                        dp[i][j] = true;
                    }
                    else{
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
                if (dp[i][j] && (j - i + 1 > maxLen)) {
                    maxLen = j - i + 1;
                    begin = i;
                }

            }
        }

        return s.substr(begin, maxLen);

    }
    
    string longestPalindrome2(string s){
		
		int len = s.length();
		if(len<2)
			return s;
		
		int maxLen = 1;
		string res = s.substr(0, 1);
		for(int i=0;i<len;i++){
			string oddStr = centerSpread(s, i, i);
			string evenStr = centerSpread(s, i, i+1);
			
			string maxLenStr = oddStr.size()>evenStr.size()?oddStr:evenStr;
			if(maxLenStr.size() > maxLen){
				maxLen = maxLenStr.size();
				res = maxLenStr;
			}
			
		}
		return res;
		
	}
	
    private:
		string centerSpread(string s, int left, int right){
	    	int len = s.size();
	    	int i=left;
	    	int j=right;
	    	while(i>=0 && j<len){
	    		if(s[i] == s[j]){
	    			i--;
	    			j++;
				}
				else{
					break;
				}
			}
			return s.substr(i+1, j-i-1);
		} 

};





int main(){
 
 string s="cbba";
 Solution sol;
 
 cout<<sol.longestPalindrome2(s);
 
 return 0;
    
}
