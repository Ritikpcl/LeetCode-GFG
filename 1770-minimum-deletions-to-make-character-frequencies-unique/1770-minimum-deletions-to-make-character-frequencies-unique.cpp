class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> mp;
        for(int i=0; i<s.length(); i++) mp[s[i]]++;
        vector<int> v;
        for(auto i: mp) v.push_back(i.second);
        sort(v.begin(),v.end());
        
        for(auto i: v) cout<<i<<" ";
        int i=v.size()-2, ans = 0;
        while(i>=0){
            if(v[i] >= v[i+1]){
                int diff = abs(v[i+1] - v[i]) + 1;
                ans += min(diff,v[i]);
                v[i] = max(0,v[i]-diff);
            }
            i--;
        }
        return ans;
    }
};