class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();

        for(int i=1; i<=n/2; i++){
            string temp = "";
            if(n%i == 0){
                for(int j=0; j<n/i; j++) temp += s.substr(0,i);
            }
            if(temp == s) return true;
        }
        return false;
    }
};