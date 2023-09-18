class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<int> ans, visit(m,0);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                    if(mat[j][i] == 0 && visit[j] == 0){
                        ans.push_back(j);
                        visit[j] = 1;
                    }
                    if(ans.size() == k) return ans;
            }
        }

        int i = 0;
        while(i<m && ans.size() < k){
            if(visit[i] == 0) ans.push_back(i);
            if(ans.size() == k) return ans;
            i++;
        }

       return ans;
    }
};