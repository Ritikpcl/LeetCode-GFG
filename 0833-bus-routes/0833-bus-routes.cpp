class Solution {
public:

    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,vector<int>> adj;
        unordered_map<int,int> visit;
        queue<pair<int,int>> q;

        for(int i=0; i<routes.size(); i++){
            for(int j=0; j<routes[i].size(); j++){
                adj[routes[i][j]].push_back(i);
            }
        }

        q.push({source,0});
        
        while(q.size()){
            int x = q.front().first;
            int n = q.front().second;
            q.pop();

            if(x == target) return n;

            for(auto i: adj[x]){
                for(auto j: routes[i]){
                    if(visit[j] == 0){
                        q.push({j,n+1});
                        visit[j] = 1;
                    }
                }
                routes[i].clear();
            }

        }
        return -1;
    }
};