class Solution {
public:
	//¼ÇÒä»¯ËÑË÷ 
    int dfs(int n, vector<int> &memory){
        if(n == 2){
            return 1;
        }
        if(memory[n] != 0)
            return memory[n];
        int res = -1;
        for(int i=1; i<n; i++){
            res = max(res, max(i*dfs(n-i, memory), i*(n-i)));
        }
        memory[n] = res;
        return res;
    }

    int integerBreak(int n) {
        vector<int> memory(n+1, 0);
        int res;
        res = dfs(n, memory);

        return res;
    }
};
