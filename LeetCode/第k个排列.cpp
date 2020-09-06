#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


class Solution {
public:

    void permutation(int*index, int pos, int len, vector<string> &result, char*strTemp, int k){

        if(pos == len){
            result.push_back(strTemp);
            return;
        }
        for(int i=0; i<len; i++){
            if(result.size() == k)
                return; 
            
            if(index[i] == 0){
                strTemp[pos] = (char)(i+1) + '0';
                index[i] = 1; 
                permutation(index, pos+1, len, result, strTemp, k);
                index[i] = 0;
            }
        }
    }

    string getPermutation(int n, int k) {

        int index[n];
        for(int i=0; i<n; i++)
            index[i] = 0;
        char strTemp[n+1];
        vector<string> result;

        permutation(index, 0, n, result, strTemp, k);     
        return result[k-1];
    }
};

int main(){
	
	Solution s;
	cout<<s.getPermutation(9, 9);
	
	return 0;
}
