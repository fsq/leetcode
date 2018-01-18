class Solution {
public:
    // divide & conquer
    // like merge sort
    // for [l, r], count #(i,j)s in [l, mid], [mid+1, r]
    // plus #(i,j)s where i in [l, mid] and r in [mid+1, r]
    
    // O(nlogn) time
    // O(logn) space
    // change recursion to iteration gives O(1) space
    
    int merge_sort(vector<int>& a, int l, int r) {
        if (l>=r) return 0;
        int mid = l + ((r-l)>>1);
        int ret = merge_sort(a, l, mid) + merge_sort(a, mid+1, r);
        int i = l;
        for (int j=mid+1; j<=r; ++j) {
            // nums in [l, i] > 2*nums[j]
            while (i<=mid && (long)a[i]>(long)a[j]*2) ++i;
            ret += i - l;
        }
        inplace_merge(a.begin()+l, a.begin()+mid+1, a.begin()+r+1, greater<int>());
        return ret;
    }
    
    int reversePairs(vector<int>& nums) {
        return merge_sort(nums, 0, nums.size()-1);
    }
};