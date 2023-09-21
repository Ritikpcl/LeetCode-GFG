class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if(n2 < n1) return findMedianSortedArrays(nums2,nums1);

        int low = 0, high = n1;
        while(low <= high){
            int mid1 = low + (high-low)/2;
            int mid2 = ((n1+n2+1)/2) - mid1;
            int l1 = mid1 > 0 ? nums1[mid1-1] : INT_MIN;
            int r1 = mid2 > 0 ? nums2[mid2-1] : INT_MIN;
            int l2 = mid1 < n1 ? nums1[mid1] : INT_MAX;
            int r2 = mid2 < n2 ? nums2[mid2] : INT_MAX;
            
            int left = max(l1,r1);
            int right = min(l2,r2);
            if(right >= left){
                return (n1+n2)&1 ? left : (left+right)/2.0;
            }else if(l1 > r2) high = mid1-1;
            else low = mid1 + 1;
        }
        return 0.0;
    }
};