class Solution {
public:
    
    // https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/description/
    // O((m+n)log(nm)) binary search
    
    // count from top right corner to bottom left corner
    int count(int row, int col, int x) {
        int ret = 0, j = col;
        for (int i=1; i<=row; ++i)
            while (j>0 && i*j>x) --j;
            ret += j;
            ++i;
        }
        return ret;
    }
    
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = n*m;
        while (l<r) {
            int mid = l + ((r-l)>>1);
            if (count(m, n, mid) < k)
                l = mid + 1;
            else 
                r = mid;
        }
        return l;
    }
};