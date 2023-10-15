class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), i = n-1, j = n-2;
        while(j>=0){
            if(nums[j] >= i-j) i=j;
            j--;
        }
        return i == 0;
    }
};