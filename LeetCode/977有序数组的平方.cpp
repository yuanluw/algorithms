class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {

        int left = 0, right=A.size()-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(A[mid] > 0){
                right = mid-1;
            }
            else if(A[mid] < 0){
                left = mid+1;
            }
            else if(A[mid] == 0){
                right = mid-1;
            }
        }
        right = left;
        left = left-1;
        
        vector<int> res;
        while(left>=0 && right<A.size()){
            if(abs(A[left]) >= A[right]){
                res.emplace_back(A[right]*A[right]);
                right++; 
            }
            else{
                res.emplace_back(A[left]*A[left]);
                left--; 
            }
        }

        while(left>=0){
            res.emplace_back(A[left]*A[left]);
            left--;
        }
        while(right<A.size()){
            res.emplace_back(A[right]*A[right]);
            right++;
        }
        return res;
    }
};
