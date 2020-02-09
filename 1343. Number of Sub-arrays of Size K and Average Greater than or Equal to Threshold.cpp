class Solution {
public:
    int numOfSubarrays(vector<int>& a, int k, int th) {
        th *= k;
        int ans = 0;
        for (int i=0,s=0; i<a.size(); ++i) {
            s += a[i];
            if (i >= k) s -= a[i-k];
            if (i >= k-1 && s>=th) ++ans;
        }
        return ans;
    }
};