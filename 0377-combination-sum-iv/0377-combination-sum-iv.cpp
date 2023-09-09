class Solution {
public:
    
    int dp[1001];
    int solve(vector<int>& nums, int target)
    {   
        if(target == 0) return 1;
        
        if(dp[target] != -1) return dp[target]; 
        
        int count = 0;
        for(int i=0; i<nums.size(); i++)
            if(target >= nums[i]) count += solve(nums, target - nums[i]);
        
        return dp[target] = count;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        
        memset(dp, -1, sizeof(dp));
        return solve(nums,target);
    }
};