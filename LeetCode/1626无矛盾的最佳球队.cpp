class Solution {
    struct Pair{
        int score;
        int age;
    };
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        
        int n = scores.size();
        vector<Pair> p;
        for(int i=0; i<n; i++){
            Pair temp;
            temp.score = scores[i];
            temp.age = ages[i];
            p.emplace_back(temp);
        }

        sort(p.begin(), p.end(), [](Pair a, Pair b){   
            if(a.age == b.age)
                return a.score < b.score;
            else
                return a.age < b.age;
        });

        int dp[n];
        for(int i=0; i<n; i++){
            dp[i] = p[i].score;
            for(int j=0; j<i; j++){
                if(p[j].score <= p[i].score){
                    dp[i] = max(dp[i], dp[j]+p[i].score);
                }
            }
        }

        int res = 0;
        for(int i=0; i<n; i++)
            res = max(res, dp[i]);

        return res;
    }
};
