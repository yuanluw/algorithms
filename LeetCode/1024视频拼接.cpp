class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {

        int dp[T+1];
        for(int i=1; i<=T; i++)
            dp[i] = INT_MAX-1;
        dp[0] = 0;
        for(int i=1; i<=T; i++){
            for(auto j : clips){
                if(i>j[0] && j[1]>=i){
                    dp[i] = min(dp[i], dp[j[0]] + 1);
                }
            }
        }
        
        return dp[T] == INT_MAX-1 ? -1: dp[T];
    }
    
    int videoStitching2(vector<vector<int>>& clips, int T) {

        vector<int> maxn(T, 0);

        for(vector<int>& it: clips){
            if(it[0] < T){
                maxn[it[0]] = max(maxn[it[0]], it[1]);
            }
        }
        int last = 0, ret = 0, pre = 0;
        for(int i=0; i<T; i++){
            last = max(last, maxn[i]);
            if(i == last){
                return -1;
            }
            if(i == pre){
                ret++;
                pre = last;
            }
        }
        return ret;
    }
};
