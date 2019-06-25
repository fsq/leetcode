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
    int findInMountainArray(int target, MountainArray &a) {
        int n = a.length();
        int l=0, r=n-1;
        while (l < r) {
            int mid = (l+r+1) >> 1;
            if (a.get(mid) > a.get(mid-1))
                l = mid;
            else
                r = mid - 1;
        }
        int k = l;
        for (l=0, r=k; l<r; ) {
            int mid = (l+r+1) >> 1;
            if (a.get(mid) > target) 
                r = mid - 1;
            else 
                l = mid;
        }
        if (a.get(l)==target) return l;
        
        for (l=k,r=n-1; l<r; ) {
            int mid = (l+r) >> 1;
            if (a.get(mid) > target)
                l = mid + 1;
            else 
                r = mid;
        }
        if (a.get(l)==target) return l;
        return -1;
    }
};