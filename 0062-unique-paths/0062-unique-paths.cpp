class Solution {
public:

    // int fact(int n){
    //     if(n<=1) return 1;
    //     return n*fact(n-1);
    // }

    int uniquePaths(int m, int n) {
        // return fact(m+n-2)/(fact(m-1)*fact(n-1));

        int a = m+n-2;
        int b = m-1;
        double f = 1;

        for(int i=1; i<=b; i++){
            f = ((a-b+i)*f)/(i);
        }

        return (int)f;
    }
};