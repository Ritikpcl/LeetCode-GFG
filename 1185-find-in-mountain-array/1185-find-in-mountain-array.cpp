/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &arr) {
        int n = arr.length();
        int l = 0, h = n-1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(arr.get(mid) < arr.get(mid+1)) l = mid+1;
            else h = mid-1;
        }
        int peak = l;

        l=0, h = peak-1;
        while(l<=h){
            int mid = l + (h-l)/2;
            int val = arr.get(mid);
            if(val == target) return mid;
            if(val < target) l = mid+1;
            else h = mid-1;
        }

        l = peak, h = n-1;
        while(l<=h){
            int mid = l + (h-l)/2;
            int val = arr.get(mid);
            if(val == target) return mid;
            if(val > target) l = mid+1;
            else h = mid-1;
        }

        return -1;
    }
};