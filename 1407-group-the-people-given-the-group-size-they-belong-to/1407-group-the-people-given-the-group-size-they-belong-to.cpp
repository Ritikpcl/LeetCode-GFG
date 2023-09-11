class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> v(n),ans;
        for(int i=0; i<n; i++){
            v[i] = {groupSizes[i],i};
        }
        
        sort(v.begin(),v.end());
        vector<int> temp;
        int i = 0;
        while(i<n){
            int x = v[i][0];
            while(i<n && x--){
                temp.push_back(v[i][1]);
                i++;
            }
            ans.push_back(temp);
            temp.resize(0);
        }

        return ans;
    }
};