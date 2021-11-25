class Solution {
public:
    
    vector<int> manacher(const string& s) {
        vector<int> d(s.size());
        for (int i=0,l=0,r=-1; i<s.size(); ++i) {
            int k = i > r ? 1 : min(d[l+r-i], r-i+1);
            while (i-k>=0 && i+k<s.size() && s[i-k]==s[i+k]) {
                ++k;
            }
            d[i] = --k;
            if (i+k > r) {
                r = i + k;
                l = i - k;
            }
        }
        return d;
    }
    
    long long maxProduct(string s) {
        auto d = manacher(s);
        vector<int> r(s.size()), l=r;
        for (int k=0,i=0; i<s.size(); ++i) {
            while (k+d[k] < i) ++k;
            r[i] = max(i==0 ? 0 : r[i-1], 2*(i-k) + 1);
        }
        for (int k=s.size()-1,i=s.size()-1; i>=0; --i) {
            while (k-d[k] > i) --k;
            l[i] = max(i+1==s.size() ? 0 : l[i+1], 2*(k-i) + 1);
        }
        long long ans = 0;
        for (int i=0; i+1<s.size(); ++i)
            ans = max(ans, (long long)r[i]*l[i+1]);
        return ans;
    }
};