class Solution {
public:
    int countHomogenous(string s) {
        int i=0,j=0,mod=1e9+7;
        long long ans = 0;
        while(j<s.length()){
            while(j<s.length() && s[j] == s[i]) j++;
            long long x = j-i;
            ans = (ans %mod + x*(x+1)/2 %mod) %mod;
            i=j;
        }
        return ans;
    }
};