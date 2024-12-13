class Solution {
public:
    void Line(vector<long long>& a, int x) {
        for (int i=1; i<x; ++i) a[i-1] += 2*(x-i);
    }

    void Line2(vector<long long>& a, int x, int y) {
        vector<long long> s(a.size()+1);
        for (int i=1; i<=x; ++i) {
            // i+1 + [1..y]
            ++s[i+2];
            if (i+2+y<s.size()) --s[i+2+y];
        }
        long long cur = 0;
        for (int i=1; i<=a.size(); ++i) {
            cur += s[i];
            a[i-1] += 2 * cur;
        }
    }

    void Circle(vector<long long>& a, int x) {
        for (int i=1; i<=x/2; ++i) {
            int k = (!(x&1) && i==x/2) ? 1 : 2;
            a[i-1] += k * x;
        }
    }

    void LineCircle(vector<long long>& a, int x, int y) {
        vector<long long> s(a.size()+1);
        for (int i=1; i<=x; ++i) {
            // i * 1
            // i + [1..y/2-1]*2 + (1 or 2)
            ++s[i];
            ++s[i+1];
            if (!(y & 1)) {
                --s[i+y/2];
                --s[i+y/2+1];
            } else {
                s[i+y/2+1] -= 2;
            }
        }
        long long cur = 0;
        for (int i=1; i<=a.size(); ++i) {
            cur += s[i];
            a[i-1] += 2 * cur;
        }
    }

    vector<long long> countOfPairs(int n, int x, int y) {
        if (y < x) swap(x, y);
        long long a = x - 1, b = y - x + 1, c = n - y;
        vector<long long> ans(n);

        if (x == y) {
            Line(ans, n);
            return ans;
        }

        if (a) Line(ans, a);  // both points between 1..x-1
        if (c) Line(ans, c);  // both points between y+1..n
        if (a && c) Line2(ans, a, c); // one in a, one in c
        if (b) Circle(ans, b); // both points in circle
        if (a && b) LineCircle(ans, a, b); // one in a, one in circle
        if (c && b) LineCircle(ans, c, b); // one in b, one in circle
        return ans;
    }
};