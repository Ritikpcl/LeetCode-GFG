class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size(), i = 0, e = 0, o = n-1;
        while(e < o){
            if(nums[i]&1){
                swap(nums[o--],nums[i]);
            }else {
                swap(nums[e++],nums[i]);
            }
            if(e > i) i = e;
        }
        return nums;
    }
};