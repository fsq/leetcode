class Solution {
public:
    const int M = 1000000007;

    long long pow(long long x, int p) {
        if (p==0) return 1;
        if (p==1) return x;
        auto s = pow(x, p>>1);
        auto ret = s * s % M;
        if (p & 1) {
            ret = (ret * x) % M;
        }
        return ret;
    }

    int numberOfSequence(int n, vector<int>& sk) {
        vector<int> a;
        a.push_back(sk[0]);
        for (int i=1; i<sk.size(); ++i)
            if (sk[i] > sk[i-1]+1) 
                a.push_back(sk[i] - sk[i-1] - 1);
        a.push_back(n-sk.back()-1);

        int tot = accumulate(a.begin(), a.end(), 0), m = a.size();
        long long ans = pow(2, tot-a.front()-a.back()-(a.size()-2));

        vector<long long> f(tot+1);
        f[0] = 1;
        for (int i=1; i<=tot; ++i) {
            f[i] = f[i-1] * i % M;
        }
        
        // a/b%m == a*b^(m-2)%m
        ans = ans * f[tot] % M;
        for (auto x : a) {
            ans = ans * pow(f[x], M-2) % M;
        }
        return ans;
    }
};