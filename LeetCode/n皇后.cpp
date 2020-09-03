#include<iostream> 
#include<vector>
#include<string>

using namespace std;


class Solution {
public:

    bool check(vector<string> dp, int row, int col, int n){

        bool result = true;
        for(int i=0;i<n;i++){
            if(dp[i][col] == 'Q')
                return false;
            if(dp[row][i] == 'Q')
                return false;
        }
        for(int i=row-1, j=col-1; i>=0 &&j>=0; i--, j--){
            if(dp[i][j] == 'Q')
                return false;
        }
        for(int i=row-1, j=col+1; i>=0 &&j<n; i--, j++){
            if(dp[i][j] == 'Q')
                return false;
        }
        return true;
    }

    void generate(vector<vector<string> > &result, vector<string> &dp, int row, int n){
        if(row == n){
            result.push_back(dp);
        }
        else{
            for(int col=0; col<n; col++){
                if(check(dp, row, col, n)){
                    dp[row][col] = 'Q';
                    generate(result, dp, row+1, n);
                    dp[row][col] = '.';
                }
            }
        }
    }

    vector<vector<string> > solveNQueens(int n) {
        
        vector<vector<string> > result ;

        vector<string> dp(n, string(n, '.'));

        generate(result, dp, 0, n);
        return result;
    }
};



int main(){
	
	Solution s;
	vector<vector<string> > result = s.solveNQueens(8);
	cout<<result.size()<<endl;
	for(int i=0;i<result.size(); i++){
		for(int j=0; j<result[i].size(); j++)
			cout<<result[i][j]<<endl;
		cout<<endl;
	}

	
	
	return 0;
}
