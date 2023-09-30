class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int n = nums.size(), mini = INT_MIN;
        for(int i=n-1; i>=0; i--){
            if(nums[i] < mini) return true;
            while(s.size() && nums[i] > s.top()){
                mini = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};