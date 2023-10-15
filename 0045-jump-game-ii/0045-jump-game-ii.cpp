class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), maxi = 0, end = 0, ans = 0;
        for(int i=0; i<n-1; i++){
            maxi = max(maxi,nums[i]+i);
            if(i == end){
                ans++;
                end = maxi;
            }
        }
        return ans;
    }
};