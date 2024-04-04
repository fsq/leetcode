class Solution {
public:

    bool ok(int x, map<int,int>& m) {
        for (auto pr: m)
            if (abs(pr.first-x) > 2)
                return false;
        return true;
    }

    long long continuousSubarrays(vector<int>& a) {
        long long ans = 0;
        map<int,int> m;
        for (int l=0, r=0; l<a.size(); ++l) {
            while (r<a.size() && ok(a[r], m)) {
                ++m[a[r]];
                ++r;
            }
            ans += r - l;
            if (m[a[l]] == 1) {
                m.erase(a[l]);
            } else {
                --m[a[l]];
            }
        }
        return ans;
    }
};