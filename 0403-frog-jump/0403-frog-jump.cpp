class Solution {
public:

    int dp[2001][2001];
    bool solve(vector<int>& stones, int i, int prev){
        
        if(i==stones.size()-1) return true;
        if(dp[i][prev] != -1) return dp[i][prev];
        int k = stones[i]-stones[prev];
        vector<int> trav = {k-1,k,k+1};
        bool ans = false;
        for(int j = 0; !ans && j<3; j++){
            int idx = lower_bound(stones.begin(), stones.end(), trav[j]+stones[i]) - stones.begin();

            if(idx <= i || idx >= stones.size() || stones[idx] != stones[i]+trav[j]) continue;
            ans = solve(stones,idx,i);
        }
        return dp[i][prev] = ans;
    }

    bool canCross(vector<int>& stones) { 
        memset(dp,-1,sizeof(dp));
        if(stones[1] != 1) return false;
        return solve(stones,1,0);
    }
};