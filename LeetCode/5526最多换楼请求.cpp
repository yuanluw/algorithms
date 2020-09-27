class Solution {
public:

    void check(vector<vector<int>>& requests, vector<int> &sum, int cur, int deal, int &maxDeal){
        //����������ҲС�����Ž� ֱ�ӷ���
        if(requests.size()-cur+deal < maxDeal)
            return;
        //��������������
        if(cur == requests.size()){
            for(int i=0; i<sum.size(); i++){
                if(sum[i] != 0){
                    return;
                }
            }
            maxDeal = max(maxDeal, deal);
            return;
        }
        //����
        sum[requests[cur][0]]--;
        sum[requests[cur][1]]++;
        check(requests, sum, cur+1, deal+1, maxDeal);
        sum[requests[cur][0]]++;
        sum[requests[cur][1]]--;
        //������
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
