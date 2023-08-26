// class Solution {
// public:
//     //DP solution
//     int dp[1001][1001];
//     int solve(vector<vector<int>>& pairs, int i, int prev){
//         if(i >= pairs.size()) return 0;
//         if(prev != -1 && dp[i][prev] != -1) return dp[i][prev];
//         int not_take = solve(pairs,i+1, prev);
//         int take = 0;
//         if(prev == -1 || pairs[i][0] > pairs[prev][1]){
//             take = 1 + solve(pairs,i+1,i);
//         }

//         int res = max(take,not_take);
//         if(prev != -1) dp[i][prev] = res;
//         return res;
//     }

//     int findLongestChain(vector<vector<int>>& pairs) {
//         sort(pairs.begin(),pairs.end());
//         memset(dp, -1, sizeof(dp));
//         return solve(pairs,0,-1);
//     }
// };


class Solution {
public:

    static bool comp(vector<int>& a, vector<int>& b){
        if(a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),comp);
        int cnt = 1, prev=0;
        for(int i=1; i<pairs.size(); i++){
            if(pairs[prev][1] < pairs[i][0]){
                cnt++;
                prev = i;
            }
        }
        return cnt;
    }
};