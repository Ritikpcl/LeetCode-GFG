class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long cnt = 0;
        int i = n-2;
        while(i>=0){
            if(nums[i] > nums[i+1]){
                int x = nums[i] / nums[i+1] + (nums[i] % nums[i+1] != 0);
                cnt += (x-1);
                nums[i] /= x;
            }
            i--;
        }
        return cnt;
    }
};