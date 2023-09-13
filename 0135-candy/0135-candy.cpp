class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> LR(n,1), RL(n,1);
        int cnt = 1;
        for(int i=1; i<n; i++){
            if(ratings[i] > ratings[i-1]){
                cnt ++;
                LR[i] = cnt;
            }else cnt = 1;
        }

        cnt = 1;
        for(int i=n-2; i>=0; i--){
            if(ratings[i] > ratings[i+1]){
                cnt++;
                RL[i] = cnt;
            }else cnt = 1;
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            ans += max(LR[i],RL[i]);
        }
        
        return ans;
    }
};