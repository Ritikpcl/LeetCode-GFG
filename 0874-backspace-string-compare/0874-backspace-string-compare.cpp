class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        int n=s.length(), m=t.length(), i=n-1, j=m-1, skip1=0, skip2=0;
        
        while(i>=0 || j>=0){
            
            char a = '$', b = '$';

            while(i>=0){
                if(s[i] == '#'){
                    i--;
                    skip1++;
                }else if(skip1){
                    i--;
                    skip1--;
                }else break;
            }
            
            while(j>=0){
                if(t[j] == '#'){
                    j--;
                    skip2++;
                }else if(skip2){
                    j--;
                    skip2--;
                }else break;
            }

            if(i>=0) a = s[i];
            if(j>=0) b = t[j];

            if(a != b) return false;
            i--,j--;
        }

        return true;
    }
};