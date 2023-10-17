class Solution {
public:

    int find_parent(vector<int>& parent, int x){
        if(parent[x] == x) return x;
        return parent[x] = find_parent(parent,parent[x]);
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parent(n);
        for(int i=0; i<n; i++) 
            parent[i] = i;
        
        for(int i=0; i<n; i++){
            if(leftChild[i] != -1){
                int p_i = find_parent(parent,i);
                if(parent[leftChild[i]] != leftChild[i]) return false;
                if(p_i == leftChild[i]) return false;
                parent[leftChild[i]] = p_i;
            }

            if(rightChild[i] != -1){
                int p_i = find_parent(parent,i);
                if(parent[rightChild[i]] != rightChild[i]) return false;
                if(p_i == rightChild[i]) return false;
                parent[rightChild[i]] = p_i;
            }
        }
        
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(parent[i] == i) cnt++;
        }

        return cnt == 1;
    }
};