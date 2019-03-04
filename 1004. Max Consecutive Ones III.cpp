class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        int l, r, c;
        for (c=0,l=0,r=0; r<a.size(); ++r) {
            if (a[r]==0) ++c;
            if (c>k && a[l++]==0) --c;
        }
        return r-l;
    }
};