class Solution {
public:

    int f[16385][14][14];
    int g[16385][14][14];

    vector<int> trace(int m, int x, int y) {
        vector<int> ans;
        while (m) {
            ans.push_back(x);
            auto nx = g[m][x][y];
            m ^= 1 << x;
            x = nx;
        }
        return ans;
    }

    int dp(vector<int>& a, int vis, int first, int last) {
        int& ans = f[vis][first][last];
        if (ans != -1) return ans;
        ans = INT_MAX;

        if (__builtin_popcount(vis) == 1) {
            if (first == last) {
                ans = abs(first - a[first]);
                g[vis][first][last] = first;
            }
        } else {
            if (first == last) {
                ans = INT_MAX;
                goto ret;
            }
            int m = vis ^ (1 << first);
            for (int next=0; next<a.size(); ++next)
                if ((m >> next) & 1) {
                    int ff = dp(a, m, next, last);
                    if (ff == INT_MAX) continue;
                    ff = ff - abs(last-a[next]) + abs(last-a[first]) + abs(first-a[next]);
                    if (ff < ans) {
                        ans = ff;
                        g[vis][first][last] = next;
                    }
                }
        }
        ret:
        return ans;
    }

    vector<int> findPermutation(vector<int>& nums) {
        memset(f, -1, sizeof(f));
        int minf = INT_MAX;
        vector<int> ans;
        // optimize: x is always 0
        for (int x=0; x<1; ++x)
            for (int y=0; y<nums.size(); ++y)
                if (x!=y) {
                    int cost = dp(nums, (1<<nums.size())-1, x, y);
                    auto b = trace((1<<nums.size())-1, x, y);
                    if (cost < minf) {
                        minf = cost;
                        ans = b;
                    } else if (cost == minf) {
                        ans = min(ans, b);
                    }
                }
        return ans;
    }
};