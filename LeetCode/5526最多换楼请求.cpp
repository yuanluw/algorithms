class Solution {
public:

    void check(vector<vector<int>>& requests, vector<int> &sum, int cur, int deal, int &maxDeal){
        //后续都满足也小于最优解 直接返回
        if(requests.size()-cur+deal < maxDeal)
            return;
        //处理完所有请求
        if(cur == requests.size()){
            for(int i=0; i<sum.size(); i++){
                if(sum[i] != 0){
                    return;
                }
            }
            maxDeal = max(maxDeal, deal);
            return;
        }
        //处理
        sum[requests[cur][0]]--;
        sum[requests[cur][1]]++;
        check(requests, sum, cur+1, deal+1, maxDeal);
        sum[requests[cur][0]]++;
        sum[requests[cur][1]]--;
        //不处理
        check(requests, sum, cur+1, deal, maxDeal);

    }

    int maximumRequests(int n, vector<vector<int>>& requests) {

        vector<int> sum(n, 0);
        int cur = 0;
        int deal = 0;
        int maxDeal = 0;
        check(requests, sum, cur, deal, maxDeal);

        return maxDeal;

    }
};
