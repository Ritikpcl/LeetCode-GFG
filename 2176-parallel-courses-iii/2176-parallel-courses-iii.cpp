class Solution {
public:
    
    int minimumTime(int n, vector<vector<int>>& mat, vector<int>& time) {
        
        vector<int> adj[n+1];
        for(auto it : mat)
        {
            int prev = it[0], next = it[1];
            adj[next].push_back(prev);
        }
        
        vector<int> dp(n+1,-1);
        for(int i = 1; i <= n; i++)
        {
            if(dp[i] == -1)
                dp[i] = dfs(i,adj,time,dp);
        }
        
        return *max_element(dp.begin(), dp.end());
    }
    
    int dfs(int node, const vector<int> adj[], const vector<int>& time, vector<int>& dp)
    {
        if(dp[node] != -1) return dp[node];
        
        int timeToStart = 0;
        for(int child : adj[node])
        {
            timeToStart = max(timeToStart, dfs(child, adj, time, dp));
        }
    
        return dp[node] = (timeToStart + time[node-1]);
    }
};