class Solution {
public:

    void solve(string& s, int i, set<string>& ans){
        if(i >= s.length()) return;
        solve(s,i+1,ans);
        ans.insert(s);
        if(s[i] >= 'A'){
            if(s[i] >= 'a') s[i] -= 32;
            else s[i] += 32;
            ans.insert(s);
        }
        solve(s,i+1,ans);
    }

    vector<string> letterCasePermutation(string s) {
        set<string> ans;
        solve(s,0,ans);
        vector<string> res(ans.begin(),ans.end());
        return res;
    }
};