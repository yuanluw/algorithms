class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        int len1 = A.size(), len2 = B.size();

        int posA = 0, posB = 0;
        vector<vector<int>> result;
        while(posA < len1 && posB < len2){
            if(A[posA][1] >= B[posB][0] && B[posB][1] >= A[posA][0]){
                vector<int> temp;
                temp.push_back(max(A[posA][0], B[posB][0]));
                temp.push_back(min(A[posA][1], B[posB][1]));
                result.push_back(temp);
            }
            if(A[posA][1] < B[posB][1])
                posA ++;
            else
                posB ++;
        }
        return result;
    }
};
