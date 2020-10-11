class Solution {
public:

    bool canPartition(vector<int>& nums) {
        
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        if(sum%2!=0)
            return false;
        int target = sum/2;
        bool dp[nums.size()][target+1];
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<=target; j++)
                dp[i][j] = false;
        }
        if(nums[0] <= target)
            dp[0][nums[0]] = true;
        dp[0][0] = true;
        for(int i=1; i<nums.size(); i++){
            for(int j=0; j<=target; j++){
                dp[i][j] = dp[i-1][j];
               //cout<<dp[i][j] << " ";
                if(nums[i] <= j){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
                }

            }
            //cout<<endl;
        }

        return dp[nums.size()-1][target];

    }
    //¿Õ¼äÓÅ»¯ 
    bool canPartition2(vector<int>& nums) {
        
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        if(sum%2!=0)
            return false;

        int target = sum/2;
        bool dp[target+1];
        for(int j=0; j<=target; j++)
            dp[j] = false;
        if(nums[0] <= target)
            dp[nums[0]] = true;
        dp[0] = true;
        for(int i=1; i<nums.size(); i++){
            for(int j=target; j>=nums[i]; j--){
                if(dp[target])
                    return true;
                dp[j] = dp[j] || dp[j-nums[i]];
            }
        }

        return dp[target];
    }
};
