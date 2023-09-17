class Solution {
public:

    class Node{
        public:

        int value;
        int path;
        int dis;

        Node(int value, int path, int dis){
            this->value = value;
            this->path = path;
            this->dis = dis;
        }
    };

    int shortestPathLength(vector<vector<int>>& graph) {
        queue<Node> q;
        set<pair<int,int>> visit;
        int n = graph.size();
        int target = (1 << n) - 1;

        for(int i=0; i<n; i++){
            int path = 1 << i;
            Node newNode(i,path,0);
            q.push(newNode);
            visit.insert({i,path});
        }

        while(q.size()){
            Node node = q.front();
            q.pop();

            int val = node.value;
            int path = node.path;
            int dis = node.dis;

            if(path == target) return dis;

            for(auto i: graph[val]){
                int newPath = path | (1 << i);
                if(visit.find({i,newPath}) == visit.end()){
                    Node newNode(i,newPath,dis+1);
                    q.push(newNode);
                    visit.insert({i,newPath});
                }
            }
        }
        return -1;
    }
};