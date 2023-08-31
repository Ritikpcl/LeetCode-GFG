class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        
        sort(clips.begin(),clips.end());
        int i=0, ans=0, start=0, end=0, n=clips.size();
        while(end<time){
            while(i<n && clips[i][0] <= start){
                end = max(end,clips[i][1]);
                i++;
            }
            if(start == end) return -1;
            start = end;
            ans++;
        }
        return ans;
    }
};