class Solution {
public:
    int maxSelectedElements(vector<int>& a) {
        sort(a.begin(), a.end());
        unordered_map<int, int> f;
        int ans = 0;
        for (auto x: a) {
            f[x+1] = max(f[x+1], f[x] + 1);
            f[x] = max(f[x], f[x-1] + 1);
            ans = max(ans, max(f[x], f[x+1]));
        }
        return ans;
    }

    int maxSelectedElements1(vector<int>& a) {
        map<int, int> m;
        for (auto x : a) ++m[x], m[x+1] += 0;

        int f0=0, f1=0;
        int ans = 0;
        auto prev = m.end();
        for (auto it=m.begin(); it!=m.end(); ++it) {
            int i = it->first;
            int g0=0, g1=0;
            if (it->second > 0) {
                g0 = 1;
            }
            if (prev!=m.end() && prev->first==i-1) {
                if (it->second > 0) {
                    g0 = max(f0, f1) + 1;
                }
                if (prev->second>=2) {
                    g1 = f0 + 1;
                }
                if (prev->second>=1) {
                    g1 = max(g1, f1 + 1);
                }
            }
            prev = it;
            ans = max(ans, max(g0, g1));
            f0 = g0;
            f1 = g1;
        }
        return ans;
    }
};