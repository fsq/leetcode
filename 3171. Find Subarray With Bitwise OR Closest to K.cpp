class Solution {
public:

    void update(vector<int>& b, int x, int k) {
        for (int i=0; i<31; ++i) {
            b[i] += ((x >> i) & 1) * k;
        }
    }

    int sum(vector<int>& b) {
        int x = 0;
        for (int i=0; i<31; ++i)
            if (b[i] > 0)
                x |= 1 << i;
        return x;
    }

    int minimumDifference(vector<int>& nums, int k) {
        vector<int> a;
        for (auto x : nums)
            if (a.empty() || x != a.back())
                a.push_back(x);
        vector<int> b(31);
        int ans = abs(k - a[0]);
        for (int l=0,r=0; r<a.size(); ++r) {
            update(b, a[r], 1);
            while (sum(b)>=k) {
                ans = min(ans, abs(sum(b)-k));
                update(b, a[l++], -1);
            }
            if (l <= r)
                ans = min(ans, abs(sum(b)-k));
        }
        return ans;
    }
};