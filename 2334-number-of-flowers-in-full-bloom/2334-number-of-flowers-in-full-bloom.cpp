class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start,end,ans;
        
        for(int i=0; i<flowers.size(); i++){
            start.push_back(flowers[i][0]);
            end.push_back(flowers[i][1]);
        }

        sort(start.begin(),start.end());
        sort(end.begin(),end.end());

        int n = people.size();
        for(int i=0; i<n; i++){
            int idx1 = upper_bound(start.begin(),start.end(),people[i])-start.begin();
            int idx2 = lower_bound(end.begin(),end.end(),people[i])-end.begin();
            ans.push_back(abs(idx2-idx1));
        }
        return ans;
    }
};