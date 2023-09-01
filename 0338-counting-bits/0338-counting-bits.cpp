class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0; i<=n; i++){
            int cnt = 0;
            int x = i;
            while(x){
                cnt += (x&1);
                x = x >> 1;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};