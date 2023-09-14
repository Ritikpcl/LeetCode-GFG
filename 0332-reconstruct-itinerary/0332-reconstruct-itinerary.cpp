class Solution {
public:

    bool dfs(unordered_map<string,set<string>>& mp, map<pair<string,string>,int>& visit, string& s, vector<string>& ans, int n){
        ans.push_back(s);
        bool res = false;
        string temp = "";
        for(auto i: mp[s]){
            if(visit[{s,i}] > 0){
                visit[{s,i}]--;
                res = dfs(mp,visit,i,ans,n);
                if(!res) visit[{s,i}]++;
            }
        }

        if(ans.size() != n+1){
            ans.pop_back();
            return false;
        } 
        else return true;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        vector<string> ans;
        unordered_map<string,set<string>> mp;
        map<pair<string,string>,int> visit;
        for(int i=0; i<n; i++){
            mp[tickets[i][0]].insert(tickets[i][1]);
            visit[{tickets[i][0],tickets[i][1]}]++;
        }
        string str = "JFK";
        dfs(mp,visit,str,ans,n);
        return ans;
    }
};