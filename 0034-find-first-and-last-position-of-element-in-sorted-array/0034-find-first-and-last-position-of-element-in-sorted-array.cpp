class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size(), low = 0, high = n-1;
        if(n == 0) return {-1,-1};
        int left = -1, right = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] < target) low = mid+1;
            else high = mid-1;
        }
        left = low;
        if(left >= n || nums[left] != target) return {-1,-1};

        low = 0, high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] > target) high = mid-1;
            else low = mid+1;
        }
        right = high;
        if(right < 0 || nums[right] != target) return {-1,-1};

        return {left,right};

    }
};