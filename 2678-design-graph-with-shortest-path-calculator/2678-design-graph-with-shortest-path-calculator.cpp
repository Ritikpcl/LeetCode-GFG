class Graph {
public:

    vector<vector<pair<int,int>>> adj;
    int n;

    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        adj.resize(n);
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> dis(n,INT_MAX);
        dis[node1] = 0;
        queue<vector<int>> q;
        q.push({node1,0});
        while(q.size()){
            vector<int> v = q.front();
            q.pop();
            int x = v[0], d = v[1];
            for(int i=0; i<adj[x].size(); i++){
                int a = adj[x][i].first;
                int b = adj[x][i].second;
                if(dis[a] > d + b){
                    dis[a] = d+b;
                    q.push({a,d+b});
                }
            }
        }
        return dis[node2] == INT_MAX ? -1 : dis[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */