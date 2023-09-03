class Solution {
public:

    int solve(string& s, int i, int prev){
        
        if(s[prev] == '0'){
            if(i<0) return 0;
            else if(s[i] == '5' || s[i] == '0') return 0;
        }

        if(s[prev] == '5'){
            if(i<0) return 1;
            else if(s[i] == '2' || s[i] == '7') return 0;
        }

        if(i<0) return 1;

        int delte = 1 + solve(s,i-1,prev-1);

        int not_delte = INT_MAX;
        if(s[prev] == '0' || s[prev] == '5'){
            not_delte = 1 + solve(s,i-1,prev);
        }

        return min(delte,not_delte);
    }

    int minimumOperations(string num) {
        int n = num.length();
        if(n == 1) return num[0] != '0';
        return solve(num,n-2,n-1);
    }
};