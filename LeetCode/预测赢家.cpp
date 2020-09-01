class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {

        int n = nums.size();
        if(n%2 == 0)
            return true;
        //return total(nums, 0, n-1, 1) >= 0;

        auto dp = vector<vector<int>> (n, vector<int>(n));
        for(int i=0;i<n;i++)
            dp[i][i] = nums[i];

        for(int i=n-2;i>=0;i--){
            for(int j=i+1; j<n; j++){
                dp[i][j] = max(nums[i]-dp[i+1][j], nums[j]-dp[i][j-1]);
            }
        }
        return dp[0][n-1] >= 0;
    }

    int total(vector<int>& nums, int start, int end, int turn){

        if(start == end)
            return nums[start]*turn;

        int scoreStart = nums[start]*turn + total(nums, start+1, end, -turn);
        int scoreEnd = nums[end]*turn + total(nums, start, end-1, -turn);
        return max(scoreStart*turn, scoreEnd*turn)*turn;
    }

};
