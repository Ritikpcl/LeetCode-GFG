class Solution {
public:

    //O(nlogn)
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     vector<int> ans;
    //     priority_queue<pair<int,int>> pq;
    //     for(int i=0; i<k; i++) pq.push({nums[i],i});
    //     int i=0,j=k-1;
    //     while(j<n){
    //         while(pq.size() && pq.top().second < i) pq.pop();
    //         int x = pq.top().first;
    //         int idx = pq.top().second;
    //         ans.push_back(x);
    //         if(idx == i){
    //             pq.pop();
    //         }
    //         i++;
    //         j++;
    //         if(j<n)pq.push({nums[j],j});
    //     }
    //     return ans;
    // }

    //O(n)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;
        for(int i=0; i<n; i++){
            if(dq.size() && dq.front() <= i-k) dq.pop_front();
            while(dq.size() && nums[i] > nums[dq.back()]) dq.pop_back();
            dq.push_back(i);
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
















};