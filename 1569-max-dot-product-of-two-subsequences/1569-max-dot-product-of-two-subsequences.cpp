class Solution {
public:

    int dp[501][501];
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j){
        if(i>=nums1.size() || j>=nums2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int a = solve(nums1,nums2,i+1,j+1);
        int b = solve(nums1,nums2,i,j+1);
        int c = solve(nums1,nums2,i+1,j);
        return dp[i][j] = max({a,b,c,a+nums1[i]*nums2[j]});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        int ans = solve(nums1,nums2,0,0);
        if(ans == 0){
            int max1 = *max_element(nums1.begin(),nums1.end());
            int min1 = *min_element(nums1.begin(),nums1.end());
            int max2 = *max_element(nums2.begin(),nums2.end());
            int min2 = *min_element(nums2.begin(),nums2.end());
            return max(max1*min2,min1*max2);
        }
        return ans;
    }
};