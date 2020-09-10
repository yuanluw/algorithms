class Solution {
public:

    void per(vector<vector<int>> &result, vector<int>candidates, int target, vector<int> &temp, int pos){

        if(target == 0){
            result.push_back(temp);
            return;
        }
        else if(target < 0)
            return;
        else{
            for(int i=pos; i<candidates.size(); i++){
                //ШЅжи
                if(i>pos && candidates[i]==candidates[i-1])
                    continue;
                if(target >= candidates[i]){
                    temp.push_back(candidates[i]);
                    per(result, candidates, target-candidates[i], temp, i+1);
                    temp.pop_back();
                }
            }
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;

        if(candidates.size() < 1)
            return result;
        
        sort(candidates.begin(), candidates.end());
        per(result, candidates, target, temp, 0);
        return result;
    }
};
