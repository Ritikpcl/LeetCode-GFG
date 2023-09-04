class Solution {
public:

    int dp[101][2];
    int solve(vector<int>& nums, int n, int last){
        if(n<0 || (n==0 && last)) return 0;
        if(dp[n][last] != -1) return dp[n][last];
        int selected = 0;
        if(n == nums.size()-1) selected = nums[n] + solve(nums,n-2,1); 
        else selected = nums[n] + solve(nums, n-2, last);
        int not_selected = solve(nums, n-1, last);

        return dp[n][last] = max(selected, not_selected);
    }

    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, nums.size()-1, 0);
    }
};