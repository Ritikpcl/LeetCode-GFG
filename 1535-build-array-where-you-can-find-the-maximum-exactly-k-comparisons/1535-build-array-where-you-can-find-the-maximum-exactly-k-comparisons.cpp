class Solution {
public:

    int mod = 1e9+7;
    long long dp[101][51][51];

    long long solve(int maxVal, int len, int n, int m, int k){
        if(len == n) return k == 0;
        if(k < 0) return 0;
        if(dp[maxVal][len][k] != -1) return dp[maxVal][len][k];
        long long ans = 0;
        for(int i=1; i<=m; i++){
            ans = (ans %mod + solve(max(maxVal,i), len+1, n, m, k - (i > maxVal)) %mod) %mod;
        }

        return dp[maxVal][len][k] = ans;
    }

    int numOfArrays(int n, int m, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,n,m,k);
    }
};