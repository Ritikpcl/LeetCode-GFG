 #define ll long long

class Solution {
public:
    
   
    
    long long maxSpending(vector<vector<int>>& values) {
        priority_queue<pair<long long, long long>,vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
        int d = 1;
        int m = values.size(), n = values[0].size();
        vector<int> row(m,n-1);
        for(int i=0; i<m; i++){
            pq.push({values[i][n-1],i});
        }
        
        ll ans = 0;
        while(pq.size()){
            ll x = pq.top().first;
            ll rw = pq.top().second;
            pq.pop();
            ans += d*x;
            d++;
            if(row[rw]>0) pq.push({values[rw][--row[rw]], rw});
        }
        return ans;
    }
};