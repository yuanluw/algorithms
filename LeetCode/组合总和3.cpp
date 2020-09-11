class Solution {
public:

    void per(vector<vector<int>> &result, vector<int> &temp, int pos, int n, int k){

        if(n==0 && temp.size() == k){
            result.push_back(temp);
            return;
        }
        else{
            for(int i=pos; i<10; i++){
                if(n >= i){
                    temp.push_back(i);
                    per(result, temp, i+1, n-i, k);
                    temp.pop_back();
                }
            }
        }

    }

    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> result;
        vector<int> temp;

        per(result, temp, 1, n, k);
        return result;

    }
};
