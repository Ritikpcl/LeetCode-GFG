class Solution {
public:

    int dp[1001][1001];
    int solve(vector<vector<int>>& pairs, int i, int prev){
        if(i >= pairs.size()) return 0;
        if(prev != -1 && dp[i][prev] != -1) return dp[i][prev];
        int not_take = solve(pairs,i+1, prev);
        int take = 0;
        if(prev == -1 || pairs[i][0] > pairs[prev][1]){
            take = 1 + solve(pairs,i+1,i);
        }

        int res = max(take,not_take);
        if(prev != -1) dp[i][prev] = res;
        return res;
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        memset(dp, -1, sizeof(dp));
        return solve(pairs,0,-1);
    }
};