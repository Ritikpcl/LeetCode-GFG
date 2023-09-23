class Solution {
public:

    int dp[1001][1001];

    static bool comp(string& a, string& b){
        return a.length() < b.length();
    }

    bool check(string& a, string& b){
        if(a.length() != b.length()-1) return false;
        
        int i=0, j=0, flag=1;
        while(i<a.length() && j<b.length()){
            if(a[i] != b[j]){
               if(flag){
                   flag = 0;
                   i--;
               }else return false;
            }
            i++;
            j++;
        }
        return true;
    }

    int solve(vector<string>& words, int i, int prev){
        if(i >= words.size()) return 0;
        if(prev != -1 && dp[i][prev] != -1) return dp[i][prev];
        int not_select = solve(words,i+1,prev);
        int select = 0;
        if(prev == -1 || check(words[prev],words[i])){
            select = 1 + solve(words,i+1,i);
        }
        int ans = max(not_select,select);
        if(prev != -1) dp[i][prev] = ans;
        return ans;
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        memset(dp,-1,sizeof(dp));
        return solve(words,0,-1);
    }
};