class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {

        int left = 1, right = getMax(piles);

        while(left <= right){
            int mid = left + (right-left)/2;
            int cnt = split(piles, mid);
            if(cnt > H){
                left = mid+1;
            }
            else if(cnt < H){
                right = mid-1;
            }
            else{
                right = mid-1;
            }
        }
        return left;
    }

    int split(vector<int> piles, int k){

        int cnt = 0;
        for(int i=0; i<piles.size(); i++){
            cnt += piles[i]/k;
            if(piles[i]%k)
                cnt ++;
        }
        return cnt;
    }

    int getMax(vector<int> piles){
        int t=piles[0];
        for(int i=1; i<piles.size(); i++)
            t = max(t, piles[i]);
        return t;
    }
};
