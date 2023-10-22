class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int ans = nums[k];
        int i=k-1, j=k+1, n = nums.size(), mini = nums[k], len = 1;
        while(i>=0 && j<n){
            if(nums[i] > nums[j]){
                mini = min(nums[i--],mini);
                ans = max(ans, ++len*mini);
            }else{
                mini = min(nums[j++],mini);
                ans = max(ans, ++len*mini);
            }
        }

        int x = len;
        while(i>=0){
            mini = min(mini,nums[i--]);
            ans = max(ans,++x*mini);
        }

        x = len;
        while(j<n){
            mini = min(mini,nums[j++]);
            ans = max(ans,++x*mini);
        }

        return ans;
    }
};