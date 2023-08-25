class Solution {
public:
    int dp[2001][101][101];
    bool solve(string& s1, string& s2, string& s3, int idx, int i, int j){
        if(idx >= s3.length()) return true;
        if(dp[idx][i][j] != -1) return dp[idx][i][j];
        bool ans = false;
        if(s1[i] == s3[idx]) ans = solve(s1,s2,s3,idx+1,i+1,j);
        if(s2[j] == s3[idx] && !ans) ans = solve(s1,s2,s3,idx+1,i,j+1);
        return dp[idx][i][j] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length() != s3.length()) return false;
        memset(dp, -1, sizeof(dp));
        return solve(s1,s2,s3,0,0,0);
    }
};