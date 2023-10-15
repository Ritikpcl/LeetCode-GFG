class Solution {
public:
    bool checkValidString(string s) {
        
        int n = s.length();
        int minRight = 0, maxRight = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                minRight++;
                maxRight++;
            }else if(s[i] == ')'){
                minRight--;
                maxRight--;
            }else if(s[i] == '*'){
                minRight--; // if * = ')'
                maxRight++; // if * = '('
            }

            if(maxRight < 0) return false;
            minRight = max(minRight,0);
        }
        return minRight == 0;
    }
};