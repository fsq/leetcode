class Solution {
public:
    int n, mx, ans = 0;

    int find(vector<int>& c, int s, int x) {
        if (x > n) return s;
        s += c[x-1];
        return max(find(c, s, x*2), find(c, s, x*2+1));
    }

    int f(vector<int>& c, int p, int x) {
        p += c[x-1];
        if (x*2 > n) {
            ans += mx - p;
            return mx - p;
        }
        int fl = f(c, p, x*2), fr = f(c, p, x*2+1);
        // cout << x << ' ' << fl << ' ' << fr << endl;
        ans -= min(fl, fr);
        return min(fl, fr);
    }

    int minIncrements(int _n, vector<int>& cost) {
        n = _n;
        mx = find(cost, 0, 1);
        f(cost, 0, 1);
        return ans;
    }
};