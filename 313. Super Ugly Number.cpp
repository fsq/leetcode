class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size();
        vector<int> a{1}, p(m, 0);
        while (a.size() < n) {
            int k = 0, mi = INT_MAX;
            for (int i=0; i<m; ++i)
                if (a[p[i]]*primes[i] < mi) {
                    mi = a[p[i]] * primes[i];
                    k = i;
                }
            a.push_back(a[p[k]] * primes[k]);
            for (int i=0; i<m; ++i)
                if (a[p[i]]*primes[i] == mi)
                    ++p[i];
        }
        return a.back();
    }
};