// class Solution {
// public:

//     int solve(vector<vector<int>>& mat, int x, int y, int m, int n, vector<vector<int>>& ans, vector<vector<int>>& dp){
        
//         if(x<0 || y<0 || x>=m || y>=n) return 1e8;
//         // if(dp[x][y] != -1 || mat[x][y] == 0) return dp[x][y] = 0;

//         int res = 1 + min({
//             solve(mat,x+1,y,m,n,ans,dp),
//             solve(mat,x-1,y,m,n,ans,dp),
//             solve(mat,x,y+1,m,n,ans,dp),
//             solve(mat,x,y-1,m,n,ans,dp)
//         });

//         // ans[x][y] = res;
//         // return dp[x][y] = res;
//         return res;
//     }


//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
//         int m = mat.size(), n = mat[0].size();
//         vector<vector<int>> dp(m, vector<int>(n,-1)), ans(m, vector<int>(n,0));
        
//         for(int i=0; i<m; i++){
//             for(int j=0; j<n; j++){
//                 if(mat[i][j] == 1) solve(mat,i,j,m,n,ans,dp);
//             }
//         }
        
//         return ans;
//     }
// };









class Solution {
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int> (n,-1));
        queue<pair<int,int>> q;
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(mat[i][j] == 0)
                {
                    ans[i][j] = 0;
                    q.push(make_pair(i,j));
                }
            
        int k = 1;
        while(!q.empty())
        {
            int size = q.size();
            
            while(size--)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
            
                if(i != 0 && mat[i-1][j] == 1 && ans[i-1][j] == -1 )
                {
                    ans[i-1][j] = k;
                    q.push(make_pair(i-1,j));
                }
                    
                
                if(i != m-1 && mat[i+1][j] == 1 && ans[i+1][j] == -1)
                {
                    ans[i+1][j] = k;
                    q.push(make_pair(i+1,j));
                }
                    
                
                if(j != 0 && mat[i][j-1] == 1 && ans[i][j-1] == -1)
                {
                    ans[i][j-1] = k;
                    q.push(make_pair(i,j-1));
                }
                
                if(j != n-1 && mat[i][j+1] == 1 && ans[i][j+1] == -1)
                {
                    ans[i][j+1] = k;
                    q.push(make_pair(i,j+1));
                }
                
            }
            
            k++;
        }
        
        return ans;
        
    }
};