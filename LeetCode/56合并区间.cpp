class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if(intervals.size() < 2)
            return intervals;

        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
            if(a[0] == b[0])
                return a[1]>b[1];
            return a[0] < b[0];
        });

        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++){
            if(result[result.size()-1][1] >= intervals[i][0]){
                result[result.size()-1][1] = max(result[result.size()-1][1], intervals[i][1]);
            }
            else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};
