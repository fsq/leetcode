class Solution {
public:
    
    // https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/
    // O((n+m)logn) rolling hash + binary search
    
    int n, m;
    const long long MOD = 1e9 + 7;
    const long long P = 2;
    vector<long long> pows;
    unordered_map<int, vector<int>> map;
    
    void init_hash(int len) {
        pows.push_back(1);
        for (int i=1; i<=len; ++i) {
            int nxt = pows.back() * P;
            if (nxt > MOD) nxt %= MOD;
            pows.push_back(nxt);
        }
    }
    
    long long roll(const vector<int>& a, int i, int len, long long pre) {
        long long hash = 0;
        if (i==0) {
            for (int i=0; i<len; ++i) {
                hash += a[i] * pows[len-i-1];
                if (hash>MOD) hash %= MOD;
            }
        } else {
            hash = ((pre-pows[len-1]*a[i-1]) * P + a[i+len-1]) % MOD;
            if (hash<0) hash += MOD;
        }
        return hash;
    }
    
    bool check(const vector<int>& a, const vector<int>& b, int len) {
        map.clear();
        
        long long hash = 0;
        for (int i=0; i+len<=n; ++i) {
            hash = roll(a, i, len, hash);
            map[hash].push_back(i);
        }
        hash = 0;
        for (int i=0; i+len<=m; ++i) {
            hash = roll(b, i, len, hash);
            if (map.find(hash)==map.end()) continue;
            for (auto pos : map[hash]) 
                if (equal(a.begin()+pos, a.begin()+pos+len, b.begin()+i))
                    return true;
            
        }
        return false;
    }
    
    int findLength(vector<int>& A, vector<int>& B) {
        n = A.size(), m = B.size();
        if (n==0 || m==0) return 0;
        
        int l=0, r=min(n, m);
        
        init_hash(r);
        
        while (l<r) {
            int mid = l + ((r-l)>>1);
            if (check(A, B, mid)) {
                l = mid;
                if (r==l+1) {
                    l = check(A, B, r) ? l+1 : l;
                    break;
                }
            } else 
                r = mid - 1;
        }
        return l;
    }
};