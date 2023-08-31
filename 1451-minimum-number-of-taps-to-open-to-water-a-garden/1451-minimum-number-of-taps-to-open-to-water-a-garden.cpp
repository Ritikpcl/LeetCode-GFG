class Solution {
public:

    static bool comp(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }

    int minTaps(int n, vector<int>& ranges) {
        
        vector<vector<int>> v(n+1, vector<int> (2,0));
        for(int i=0; i<n+1; i++){
            v[i][0] = max(0,i-ranges[i]);
            v[i][1] = i+ranges[i];
        }

        sort(v.begin(), v.end(), comp);

        int i = 0, ans = 0, start = 0, end = 0;
        while(end < n){

            while(i<n+1 && v[i][0] <= start){
                end = max(end,v[i][1]);
                i++;
            }

            if(start == end) return -1;
            start = end;
            ans++;
        }

        return ans;
    }
};