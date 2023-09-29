class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = false, dec = false;
        int n = nums.size();
        int i=1;
        while(i<n && nums[i] == nums[i-1]) i++;
        if(i == n) return true;
        if(nums[i] < nums[i-1]) dec = true;
        else inc = true;
        while(i<n){
            if(dec && nums[i] > nums[i-1]) return false;
            if(inc && nums[i] < nums[i-1]) return false;
            i++;
        }
        return true;
    }
};