class Solution {
public:

    long long dp[501][501];
    int mod = 1e9+7;

    long long solve(int steps, int arrLen, int i){
        
        if(steps == 0) return i == 0;
        if(i < 0 || i >= arrLen) return 0;
        if(dp[steps][i] != -1) return dp[steps][i];

        return dp[steps][i] = (solve(steps-1,arrLen,i+1) %mod + solve(steps-1,arrLen,i-1) %mod + solve(steps-1,arrLen,i) %mod) %mod;
    }

    int numWays(int steps, int arrLen) {
        memset(dp,-1,sizeof(dp));
        return solve(steps,arrLen,0);
    }
};