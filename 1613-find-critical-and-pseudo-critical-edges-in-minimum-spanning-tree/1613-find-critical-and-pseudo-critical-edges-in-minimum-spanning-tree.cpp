class Solution {
public:

    int find_parent(int a, vector<int>& parent){
        if(parent[a] == a) return a;
        return parent[a] = find_parent(parent[a],parent);
    }

    int minSpanningTree(vector<vector<int>>& edges, vector<int>& visit, vector<int>& parent, vector<int>& rank, int skip, int checkPseudo){
      
        priority_queue<pair<int,int>, 
            vector<pair<int,int>>, 
                greater<pair<int,int>>> pq;
        
        int weight = 0;

        if(checkPseudo != -1){
            parent[edges[checkPseudo][0]] = edges[checkPseudo][1];
            rank[edges[checkPseudo][1]]++;
            weight += edges[checkPseudo][2];
        }

        for(int i=0; i<edges.size(); i++){
            if(i == skip) continue;
            int wt = edges[i][2];
            pq.push({wt, i});
        }

        while(pq.size()){
            int wt = pq.top().first;
            int i = pq.top().second;
            pq.pop();

            int x = edges[i][0];
            int y = edges[i][1];

            visit[x] = 1;
            visit[y] = 1;
            int p_x = find_parent(x,parent);
            int p_y = find_parent(y,parent);

            if(p_x != p_y){
                if(rank[p_x] > rank[p_y]) parent[p_y] = p_x, rank[p_x]++;
                else parent[p_x] = p_y, rank[p_y]++;
                weight += wt;
            }
        }

        return weight;
    }

    void reset(vector<int>& visit, vector<int>& parent, vector<int>& rank){
        int n = parent.size();
        for(int i=0; i<n; i++){
            parent[i] = i;
            visit[i] = 0;
            rank[i] = 0;
        }
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<int> visit(n,0), parent(n), rank(n,0);
        vector<vector<int>> ans(2);

        reset(visit,parent,rank);
        int minWeight = minSpanningTree(edges,visit,parent,rank,-1,-1);
        cout<<minWeight<<" ";

        for(int k=0; k<edges.size(); k++){
            reset(visit,parent,rank);
            int weight = minSpanningTree(edges,visit,parent,rank,k,-1);
            // cout<<weight<<" ";
            if(weight != minWeight){
                ans[0].push_back(k);
            }else {
                reset(visit,parent,rank);
                int weight = minSpanningTree(edges,visit,parent,rank,-1,k);
                if(weight == minWeight){
                    ans[1].push_back(k);
                }
            }
        }

        return ans;
    }
};


// class UnionFind {
// public: 
//     vector<int> parent; 
//     UnionFind(int n){
//         parent.resize(n);
//         for(int i=0;i<n;i++)
//             parent[i] = i; 
//     }
    
//     int findParent(int p) {
//         return parent[p] == p ? p : parent[p] = findParent(parent[p]); 
//     }
    
//     void Union(int u , int v) {
//         int pu = findParent(u) , pv = findParent(v); 
//         parent[pu] = pv;
//     }    
// };

// class Solution {
// public:    
//     static bool cmp(vector<int>&a , vector<int>&b) {
//         return a[2] < b[2]; 
//     }
    
//     vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
//         vector<int> critical ,  pscritical ;
//         //1
//         for(int i=0;i<edges.size();i++)
//             edges[i].push_back(i); 
        
//         //2 
//         sort(edges.begin() , edges.end() , cmp) ;
        
//         int mstwt = findMST(n,edges,-1,-1); //3
//         for(int i=0;i<edges.size();i++){
//             if(mstwt< findMST(n,edges,i,-1)) //5
//                 critical.push_back(edges[i][3]); 
//             else if(mstwt == findMST(n,edges,-1,i))  //6
//                 pscritical.push_back(edges[i][3]);
//         }
//         return {critical , pscritical};         
//     }
    
// private:
//     int findMST(int &n ,  vector<vector<int>>& edges , int block , int e) {
//         UnionFind uf(n); 
//         int weight = 0 ;
//         if(e != -1) {
//             weight += edges[e][2]; 
//             uf.Union(edges[e][0] , edges[e][1]); 
//         }
        
//         for(int i=0;i<edges.size();i++){
//             if(i == block) 
//                 continue; 
//             if(uf.findParent(edges[i][0]) == uf.findParent(edges[i][1])) //4
//                 continue; 
//             uf.Union(edges[i][0] , edges[i][1]); 
//             weight += edges[i][2]; 
//         }
        
//         //Check if all vertices are included then only it is MST. 
//         for(int i=0;i<n;i++){
//             if(uf.findParent(i) != uf.findParent(0))
//                 return INT_MAX;
//         }    
        
//         return weight; 
//     }
    
// };