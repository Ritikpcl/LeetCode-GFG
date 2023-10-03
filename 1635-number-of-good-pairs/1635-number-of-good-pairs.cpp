class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        for(auto i: mp) ans += (i.second)*(i.second-1)/2;
        return ans;
    }
};