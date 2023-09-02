class Solution {
public:

    int dp[51];
    bool check(string& s, unordered_map<string,int>& mp, int i ,int j){
        string temp = "";
        for(int k=i; k<=j; k++){
            temp += s[k];
        }
        return mp[temp];
    }

    int solve(string& s, unordered_map<string,int>& mp, int i){
        if(i >= s.length()) return 0;

        if(dp[i] != -1) return dp[i];
        int ans = 1e8;
        for(int k=i; k<s.length(); k++){
            if(check(s,mp,i,k)){
                ans = min(ans,solve(s,mp,k+1));
            }else{
                ans = min(ans, (k-i+1) + solve(s,mp,k+1));
            }
        }
        return dp[i] = ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string,int> mp;
        memset(dp,-1,sizeof(dp));
        for(int i=0; i<dictionary.size(); i++){
            mp[dictionary[i]] = 1;
        }
        return solve(s,mp,0);
    }
};