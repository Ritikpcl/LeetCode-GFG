// class Solution {
// public:
//     bool repeatedSubstringPattern(string s) {
//         int n = s.length();

//         for(int i=1; i<=n/2; i++){
//             string temp = "";
//             if(n%i == 0){
//                 for(int j=0; j<n/i; j++) temp += s.substr(0,i);
//             }
//             if(temp == s) return true;
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        int n = s.length();
        string temp = s + s;

        // deleting first and last characters
        temp.erase(0,1);
        temp.erase(2*n-2,1);
        
        vector<int> v(n);
        int i=0, j=1, len = temp.length();
        while(j<n){
            if(s[i] == s[j]) v[j++] = ++i;
            else if(i) i = v[i-1];
            else j++; 
        }

        i=0,j=0;
        while(j<len){
            if(s[i] == temp[j]) i++,j++;
            else if(i) i = v[i-1];
            else j++;
            if(i == n) return true;
        }
        return false;
    }
};