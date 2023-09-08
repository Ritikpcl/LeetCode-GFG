class Solution {
public:

    int maximalSquare(vector<vector<char>>& matrix) {
        
        int m = matrix.size(), n = matrix[0].size(), sum = 0, ans = 0;
        vector<vector<int>> dp(m+1, vector<int> (n+1,0));

        for(int i=1; i<=m; i++){
            sum = 0;
            for(int j=1; j<=n; j++){
                sum += matrix[i-1][j-1] == '1';
                dp[i][j] = sum;
            }
        }

        for(int i=1; i<=n; i++){
            sum = 0;
            for(int j=1; j<=m; j++){
                sum += dp[j][i];
                dp[j][i] = sum;
            }
        }

        for(int k=min(m,n); k>=1; k--){
            for(int i=k; i<=m; i++){
                for(int j=k; j<=n; j++){
                    int x = dp[i][j] - ( dp[i-k][j] + dp[i][j-k] - dp[i-k][j-k] );
                    if(k*k == x){
                        return x;
                    }
                }
            }
        }

        return 0;
    }
};