class Solution {
public:
    
    long long M = 1'000'000'007;
    
    int totalStrength(vector<int>& a) {
        int n = a.size();
        vector<long long> s, l(n), r(n), p(n+2), ps(n+2);
        for (int i=0; i<n; ++i) p[i+1] = (p[i] + a[i]) % M;
        for (int i=0; i<=n; ++i) ps[i+1] = (ps[i] + p[i]) % M;
        
        for (int i=0; i<n; ++i) {
            while (s.size() && a[i]<a[s.back()]) s.pop_back();
            l[i] = s.size() ? s.back() : -1;
            s.push_back(i);
        }
        s.clear();
        for (int i=n-1; i>=0; --i) {
            while (s.size() && a[i]<=a[s.back()]) s.pop_back();
            r[i] = s.size() ? s.back() : n;
            s.push_back(i);
        }
        
        long long ans = 0;
        for (int i=0; i<n; ++i) {
            long long le = l[i], re = r[i];
            long long sm = (((ps[re+1] - ps[i+1])*(i-le) - (ps[i+1] - ps[le+1])*(re-i)) % M + M) % M;
            ans = (ans + sm * a[i]) % M;
        }
        
        return ans;
    }
};