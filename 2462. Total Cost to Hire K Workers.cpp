class Solution {
public:
    long long totalCost(vector<int>& a, int k, int candidates) {
        multiset<int> s1, s2;
        int l = candidates-1, r = max<int>(candidates, a.size()-candidates);
        for (int i=0; i<=l; ++i) s1.insert(a[i]);
        for (int i=r; i<a.size(); ++i) s2.insert(a[i]);
        long long ans = 0;
        while (k--) {
            bool chose = s1.empty() ? false : (s2.empty() || *s1.begin() <= *s2.begin());
            if (chose) {
                ans += *s1.begin();
                s1.erase(s1.begin());
                if (l+1<r) {
                    s1.insert(a[l+1]);
                    ++l;
                }
            } else {
                ans += *s2.begin();
                s2.erase(s2.begin());
                if (r-1>l) {
                    s2.insert(a[r-1]);
                    --r;
                }
            }
        }
        return ans;
    }
};