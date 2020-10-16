class Solution {
public:
    int splitArray(vector<int>& nums, int m) {

        int lo = getMax(nums);
        int hi = getSum(nums);
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            int n = split(nums, mid);
            if(n == m){
                hi = mid-1;
            }
            else if(n < m){
                hi = mid-1;
            }
            else if(n > m){
                lo = mid+1;
            }
        }

        return lo;
    }

    int split(vector<int> nums, int target){

        int cnt = 0;
        int temp = 0;
        for(int i=0; i<nums.size(); i++){
            if(temp + nums[i] > target){
                cnt++;
                temp = nums[i];
            }
            else{
                temp += nums[i];
            }
        }
        return cnt+1;
    }

    int getMax(vector<int> nums){
        int t = nums[0];

        for(int i=1; i<nums.size(); i++){
            t = max(t, nums[i]);
        }
        return t;
    }

    int getSum(vector<int> nums){
        int t = 0;
        for(int i=0; i<nums.size(); i++){
            t += nums[i];
        }
        return t;
    }
};
