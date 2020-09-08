class Solution {
public:

    void per(vector<vector<int>> &result, vector<int> &temp, int pos, int k, int len){

        if(temp.size() == k){
            result.push_back(temp);
            return;
        }

        for(int i=pos;i<=len;i++){
            temp.push_back(i);
            per(result, temp, i+1, k, len);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> result;
        if(n==0 || n<k)
            return result;

        vector<int> temp;

        per(result, temp, 1, k, n);        
        return result;
    }
};
