class Solution {
public:
    string convertToTitle(int N) {
        string ans = "";
        string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        while(N){
            N--;
           ans += s[N%26]; 
           N /= 26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};