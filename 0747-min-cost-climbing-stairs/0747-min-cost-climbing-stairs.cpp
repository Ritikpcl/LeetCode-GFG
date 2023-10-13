class Solution {
public:
    
    int min_cost = INT_MAX;
    vector<int> dp;
    
    int solve(int i, vector<int>& cost, int n)
    {
        if(i >= n)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        dp[i] = cost[i] + min( solve(i+1,cost,n) , solve(i+2,cost,n) );
        return dp[i];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        dp = vector<int>(n+1,-1);
        
        int min_cost = min(solve(0,cost,n),solve(1,cost,n));
        
        return min_cost;
    }
};