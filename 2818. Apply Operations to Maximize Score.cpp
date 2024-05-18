class Solution {
public:

    const int M = 1000000007;

    int pow(int a, int x) {
        if (x == 0) return 1;
        if (x == 1) return a;
        int s = pow(a, x >> 1);
        if (x & 1) {
            return (long long)a * s % M * s % M;
        } else {
            return (long long)s * s % M;
        }
    }

    int maximumScore(vector<int>& a, int k) {
        int n = a.size();
        vector<int> s(n);
        for (int i=0; i<n; ++i) {
            int x = a[i];
            for (int p=2; p*p<=x; ++p)
                if (x % p == 0) {
                    ++s[i];
                    while (x % p == 0) {
                        x /= p;
                    }
                }
            if (x > 1) {
                ++s[i];
            }
        }
        // 左边第一个>=的，右边第一个>的
        vector<int> l(n, -1), r(n, n), q;
        for (int i=0; i<n; ++i) {
            while (q.size() && s[i] > s[q.back()]) {
                r[q.back()] = i;
                q.pop_back();
            }
            if (q.size()) {
                l[i] = q.back();
            }
            q.push_back(i);
        }
        map<int, long long> score;
        for (int i=0; i<n; ++i) {
            long long lb = i - l[i], rb = r[i] - i;
            score[a[i]] += lb * rb;
        }

        long long ans = 1;
        auto it = score.rbegin();
        while (it != score.rend() && k>0) {
            long long sc = it->first, has = it->second, chose = min<long long>(has, k);
            ans = (ans * pow(sc, chose)) % M;
            k -= chose;
            ++it;
        }
        return ans;
    }
};