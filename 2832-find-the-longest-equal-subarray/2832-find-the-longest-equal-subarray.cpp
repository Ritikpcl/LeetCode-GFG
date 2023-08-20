class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        
        map<int,vector<int>> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]].push_back(i);
        }
        
        int ans = 1;
        for(auto itr: mp){
            int i=0, j=1, cnt=k, res=1;
            vector<int> v = itr.second;
            while(i<=j && j<v.size()){
                if(v[j] - v[j-1] <= cnt+1){
                    cnt -= v[j]-v[j-1]-1;
                    j++;
                    res++;
                    ans = max(ans,res);
                }else cnt += v[i+1] - v[i] - 1, res--, i++;
            }
        }
        
        return ans;
    }
};