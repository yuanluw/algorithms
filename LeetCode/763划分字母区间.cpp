class Solution {
public:
    vector<int> partitionLabels(string S) {

        unordered_map<char, int> m;

        for(int i=0; i<S.size(); i++)
            m[S[i]] = i;
        
        vector<int> res;
        int end = 0;
        int start = 0;
        for(int i=0; i<S.size(); i++){

            end = max(m[S[i]], end);
            if(i == end){
                res.push_back(end-start+1);
                start = end+1;
                end = end+1;
            }
        }

        return res;

    }
};
