class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int len = nums.size();
        if(len <= 1){
            return len;
        }
        int dp[len];
        for(int i=0; i<len; i++)
            dp[i] = 1;

        for(int i=1; i<len; i++){
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        int result = 1;
        for(int i=0; i<len; i++)
            result = max(result, dp[i]);
        return result;
    }  
	//¶þ·Ö 
 	int lengthOfLIS2(vector<int>& nums) {
	    int len = nums.size();
	    if(len == 0)
	        return 0;
	    int dp[len];
	
	    for(int i=0; i<len; i++){
	        dp[i] = INT_MIN;
	    }
	    int maxL = 0;
	    for(int num : nums){
	        int lo = 0, hi = maxL;
	        while(lo<hi){
	            int mid = lo + (hi - lo)/2;
	            if(dp[mid] < num){
	                lo = mid+1;
	            }
	            else{
	                hi = mid;
	            }
	        }
	        dp[lo] = num;
	        if(lo == maxL)
	            maxL++;
	    }
	    return maxL;
    }   
};
