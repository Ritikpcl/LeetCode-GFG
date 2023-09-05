class Solution {
public:
    int maximumGap(vector<int>& nums) {
        
        int n = nums.size();
        if(n < 2) return 0;
        
        int mini = INT_MAX, maxi = INT_MIN;

        for(int i=0; i<n; i++){
            mini = min(mini,nums[i]);
            maxi = max(maxi,nums[i]);
        }

        int avgGap = ceil((maxi-mini)/(n-1.0));
        vector<pair<int,int>> bucket(n-1, pair<int,int>{INT_MAX,INT_MIN});

        for(int i=0; i<n; i++){
            
            if(nums[i] == mini || nums[i] == maxi) continue;

            int x = (nums[i]-mini) / avgGap;
            pair<int,int> p = bucket[x];
            bucket[x].first = min(p.first,nums[i]);
            bucket[x].second = max(p.second,nums[i]);
        }

        int prev = mini, ans = 0;
        for(int i=0; i<bucket.size(); i++){
            int a = prev;
            int b = bucket[i].first;
            if(b != INT_MIN && b != INT_MAX){
                ans = max(ans,b-a);
            }

            if(b != INT_MIN && b != INT_MAX) prev = bucket[i].second;
        }

        ans = max(ans,maxi - prev);
        return ans;
    }
};