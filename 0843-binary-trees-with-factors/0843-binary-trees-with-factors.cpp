class Solution {
public:
    
    map<int,long long> dp;
    map<int,long long> mp;
    int mod = 1e9 + 7;
    long long solve(vector<int>& arr, int i)
    {
        if(i < 0) return 0;
        
        if(dp.find(i) != dp.end()) return dp[i] % mod;
        
        long long count = 1;
        for(int k = i-1; k >= 0; k--)
            if(arr[i]%arr[k] == 0 && mp.find(arr[i]/arr[k]) != mp.end()) 
                count +=  solve(arr, k)*solve(arr, mp[arr[i]/arr[k]]);
    
        return dp[i] = count;
        
    }
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        sort(arr.begin(), arr.end());
        for(int i=0; i<arr.size(); i++) mp[arr[i]] = i;
        
        long long count = 0;
        for(int i=0; i<arr.size(); i++) 
            count += solve(arr, i);
            
        return count % mod;
    }
};