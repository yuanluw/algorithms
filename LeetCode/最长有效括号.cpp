#include<iostream>
#include<vector>
#include<stack>
#include<string>

using namespace std;


 class Solution {
public:
    int longestValidParentheses(string s) {
        
        int len = s.length();
        if (len <= 1)
            return 0;

        int *dp = new int[len+1]();
        dp[0] = 0;
        for(int i=1; i<len; i++){
        	if(s[i] == '('){
        		dp[i] = 0;
			}
			else if (s[i] == ')'){
				if(s[i-1] =='('){
					dp[i] = 2;
					if (i-2>=0)
						dp[i] = dp[i] + dp[i-2];
				}
				else if(dp[i-1]>0){
					if((i-dp[i-1]-1) >=0 && s[i-dp[i-1]-1] == '('){
						dp[i] = dp[i-1] + 2;
						if((i - dp[i-1] - 2) > 0)
							dp[i] = dp[i] + dp[i-dp[i-1]-2];
					}
				}
			}
		}
            
        for(int i=0;i<=len;i++){
            max = max > dp[i] ? max:dp[i];
        }
        return max;
    }
};


int main(){
	
	Solution s;
	
	cout<<s.longestValidParentheses("()(())");
	
	return 0;
}
