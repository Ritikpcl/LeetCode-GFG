class Solution {
public:

    int find_parent(int x, vector<int>& parent){
        if(parent[x] == x) return x;
        return parent[x] = find_parent(parent[x],parent);
    }

    bool DSU(vector<int>& parent, vector<int>& rank, int x, int y){
        int p_x = find_parent(x, parent);
        int p_y = find_parent(y, parent);

        if(p_x == p_y) return false;
        
        if(rank[p_x] > rank[p_y]){
            parent[p_y] = p_x;
        }else if(rank[p_y] > rank[p_x]) {
            parent[p_x] = p_y;
        } else {
            parent[p_y] = p_x;
            rank[p_x]++;
        }

        return true;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<int> parent(n,0), rank(n,0);

        for(int i=0; i<n; i++) parent[i] = i;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int dis = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                pq.push({dis,{i,j}});
            }
        }

        int ans = 0;
        while(pq.size()){
            int dis = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            if(DSU(parent,rank,x,y)){
                ans += dis;
            }
        }

        return ans;
    }
};