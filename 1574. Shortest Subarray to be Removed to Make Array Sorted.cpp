class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& a) {
        int j = a.size()-1;
        while (j-1>=0 && a[j]>=a[j-1]) --j;
        if (!j) return 0;
        int ans = j;
        for (int i=0; !i || a[i]>=a[i-1]; ++i) {
            while (j<a.size() && a[i]>a[j]) ++j;
            ans = min(ans, j-i-1);
        }
        return ans;
    }
};