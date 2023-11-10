class Solution {
public:

    void dfs(map<int,vector<int>>& mp, unordered_map<int,int>& visit, vector<int>& ans, int x){
        visit[x] = 1;
        ans.push_back(x);
        for(auto i: mp[x]){
            if(visit[i] == 0)
                dfs(mp,visit,ans,i);
        }
    }

    vector<int> restoreArray(vector<vector<int>>& pairs) {
        
        int n = pairs.size(), src = -1;
        map<int,vector<int>> mp;
        unordered_map<int,int> visit;
        vector<int> ans;
        for(int i=0; i<n; i++){
            int a = pairs[i][0], b = pairs[i][1];
            mp[a].push_back(b);
            mp[b].push_back(a);
        }

        for(auto i: mp){
            if(mp[i.first].size() == 1) src = i.first;
        }
        
        dfs(mp,visit,ans,src);
        return ans;
    }
};