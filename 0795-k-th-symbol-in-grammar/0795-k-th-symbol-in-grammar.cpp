class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1) return 0;
        int x = pow(2,n-2);
        if(k > x) return !kthGrammar(n-1,k-x);
        return kthGrammar(n-1,k);
    }
};

// 1 .0
// 2 .01
// 3 01.10
// 4 01.101001
// 5 0110100110.010110
// 6 01101001100101101001011001.101001
