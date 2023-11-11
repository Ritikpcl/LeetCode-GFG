class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        
        map<long long,vector<long long>> mp, preSum;
        
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]].push_back(i);
            long long x = 0;
            if(preSum[arr[i]].size()) x = preSum[arr[i]].back();
            preSum[arr[i]].push_back(i+x);
        }

        vector<long long> ans;
        for(int i=0; i<arr.size(); i++){
            // vector<long long> temp = ;
            long long n = mp[arr[i]].size();
            long long total_sum = preSum[arr[i]][n-1];
            int idx = lower_bound(mp[arr[i]].begin(),mp[arr[i]].end(),i) - mp[arr[i]].begin();
            long long prSm = idx>0 ? preSum[arr[i]][idx-1] : 0;
            long long s = idx*mp[arr[i]][idx] - (n-idx)*mp[arr[i]][idx] + total_sum - 2*prSm;
            ans.push_back(s);
        }
        return ans;
    }
};