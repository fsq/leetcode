class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> a;
        for (int i=1; i<=sqrt(n); ++i)
            if (n % i==0) {
                a.push_back(i);
                if (i*i != n)
                    a.push_back(n / i);
            }
        if (a.size() < k) return -1;
        nth_element(a.begin(), a.begin()+k-1, a.end());
        return a[k-1];
    }
};