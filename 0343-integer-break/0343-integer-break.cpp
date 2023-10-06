class Solution {
public:

    int solve(int n){
        if(n<=4) return n;
        return 3*solve(n-3);
    }

    int integerBreak(int n) {
        if(n<4) return n-1;
        return solve(n);
    }
};