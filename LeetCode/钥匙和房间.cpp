

class Solution {
public:
    void dfs(int key, const vector<vector<int>>& rooms, vector<int> &visited){
        if(visited[key])
            return;
        
        visited[key] = 1;
        vector<int> keys = rooms[key];
        for(int key: keys){
            dfs(key, rooms, visited);
        }
    }

    bool canVisitAllRooms2(vector<vector<int>>& rooms) {
        vector<int> visited(rooms.size(), 0);
        dfs(0, rooms, visited);
        for(int i : visited){
            if(i == 0)
                return false;
        }
        return true;
    }
    
    int findNext(int* dp, int len){
        for(int i=0;i<len;i++){
            if(dp[i] == 1)
                return i;
        }
        return len;
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int N = rooms.size();
        int *dp = new int[N]();
        for(int i=0;i<N;i++){
            dp[i] = 0;
        }
        dp[0] = 1;
        int index = 0;
        while(1){
            index = findNext(dp, N);
            if(index == N)
                break;
            dp[index] = 2;
            for(int i=0; i<rooms[index].size();i++){
                if(dp[rooms[index][i]] == 0)
                    dp[rooms[index][i]] = 1;
            }
        }

        for(int i=0;i<N;i++){
            if(dp[i] != 2)
                return false;
        }
        return true;
    }
};
