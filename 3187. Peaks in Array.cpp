class Solution {
public:
    vector<int> s;
    int n;

    inline int lowbit(int x) {
        return x & (-x);
    }

    void update(int i, int v) {
        for (++i; i<s.size(); i+=lowbit(i)) s[i] += v;
    }

    int query(int i) {
        int ans = 0;
        for (++i; i>0; i-=lowbit(i)) ans += s[i];
        return ans;
    }

    vector<int> countOfPeaks(vector<int>& a, vector<vector<int>>& queries) {
        n = a.size();
        s.resize(n+1);
        for (int i=1; i+1<a.size(); ++i)
            if (a[i]>a[i-1] && a[i]>a[i+1])
                update(i, 1);
        vector<int> ans;
        for (auto& q: queries) {
            if (q[0] == 1) {
                int l = q[1]+1, r = q[2]-1;
                ans.push_back(l<=r ? query(r)-query(l-1) : 0);
            } else {
                int p = q[1], v = q[2];
                vector<int> id = {p-1, p, p+1};
                vector<int> was(3), now(3);
                for (auto i: id) {
                    if (i-1<0 || i+1>=n) continue;
                    if (a[i]>a[i-1] && a[i]>a[i+1]) was[i-p+1] = true;
                }
                a[p] = v;
                for (auto i: id) {
                    if (i-1<0 || i+1>=n) continue;
                    if (a[i]>a[i-1] && a[i]>a[i+1]) now[i-p+1] = true;
                }
                for (int i=0; i<3; ++i)
                    if (was[i] && !now[i]) {
                        update(id[i], -1);
                    } else if (now[i] && !was[i]) {
                        update(id[i], 1);
                    }
            }
        }
        return ans;
    }
};