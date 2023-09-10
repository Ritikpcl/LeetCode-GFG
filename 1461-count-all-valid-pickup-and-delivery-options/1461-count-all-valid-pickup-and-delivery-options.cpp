class Solution {
public:

    int mod = 1e9+7;
    long long dp[501][501];
    long long solve(long long P, long long D, long long n){
        if(P == 0 && D == 0) return 1;
        if(dp[P][D] != -1) return dp[P][D];
        long ans = 0;
        if(P > 0) ans += (P %mod * solve(P-1,D,n) %mod) %mod;
        if(D > P) ans += ((D-P) %mod * solve(P,D-1,n) %mod) %mod;
        return dp[P][D] = ans %mod;
    }

    int countOrders(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,n,n) %mod;
    }
};