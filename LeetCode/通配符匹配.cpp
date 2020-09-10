class Solution {
public:
    bool isMatch(string s, string p) {
        s = " "+s;
        p = " "+p;

        int len1 = s.size(), len2 = p.size();
        bool dp[len1+1][len2+1];
        memset(dp, false, (len1+1)*(len2+1));
        dp[0][0] = true;
        for(int i=1; i<=len1;i++){
            for(int j=1; j<=len2; j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1]=='*'){
                    dp[i][j] = dp[i-1][j]||dp[i][j-1];
                }
            }
        }
        return dp[len1][len2];
    }
};
