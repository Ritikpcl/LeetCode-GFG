class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        
        unordered_map<int,int> mp;
        int n=nums.size(), i=0, j=0;
        long long ans = 0, sum = 0;

        while(j<n){
            
            if(j<k){
                sum += nums[j];
                mp[nums[j]]++;
                j++;
            }else{
                sum -= nums[i];
                sum += nums[j];
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                mp[nums[j]]++;
                i++, j++;
            }

            if(mp.size() >= m){
                ans = max(ans,sum);
            }
        }

        return ans;
    }
};