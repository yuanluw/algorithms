class Solution {
public:

    void per(vector<int> candidates, vector<vector<int>> &result,  int target, vector<int> temp){

        if(target == 0){
            result.push_back(temp);
        }
        else if(target < 0)
            return;
        else
            for(int i=0; i<candidates.size(); i++){
                if(candidates[i] <= target){
                    if(temp.size()>0 && temp[temp.size()-1] > candidates[i])
                        continue;
                    
                    temp.push_back(candidates[i]);
                    per(candidates, result, target-candidates[i], temp);
                    temp.pop_back();
                }
                else{
                    return;
                }
            }


    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> result;

        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        per(candidates, result, target, temp);

        return result;

    }
};
