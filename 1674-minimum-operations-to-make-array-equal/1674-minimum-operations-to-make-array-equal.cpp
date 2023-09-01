class Solution {
public:
    int minOperations(int n) {
        int lastNum = 1 + (n-1)*2;
        int tar = (1+lastNum)/2;
        int ans = 0, x = 1;
        cout<<lastNum<<" "<<tar;
        for(int i=1; i<=n/2; i++){
            ans += (tar - x);
            x = i*2+1;
        }
        return ans;
    }
};