class Solution {
public:

    int solve(vector<int>& v, int idx, int n){
        int low = idx, high = v.size()-1;
        int tar = v[idx] + n - 1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(v[mid] == tar){
                return (n - 1 - mid);
            }else if(v[mid] < tar) low = mid+1;
            else high = mid-1;
        }
        return n-low;
    }

    int minOperations(vector<int>& nums) {
        int n = nums.size(), ans = n;
        set<int> st(nums.begin(),nums.end());
        vector<int> v(st.begin(),st.end());
        sort(v.begin(),v.end());
        for(int i=0; i<v.size(); i++){
            ans = min(ans,i+solve(v,i,n));
        }
        return ans;
    }
};