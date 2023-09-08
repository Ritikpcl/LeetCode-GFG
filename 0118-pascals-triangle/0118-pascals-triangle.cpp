class Solution {
public:

    int nCr(int n, int r){
        int res = 1;

        for(int i=0; i<r; i++){
            res *= (n-i);
            res /= (i+1);
        }

        return res;
    }

    vector<vector<int>> generate(int n) {
        vector<vector<int>> v(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++){
                v[i].push_back(nCr(i,j));
            }
        }
        return v;
    }
};