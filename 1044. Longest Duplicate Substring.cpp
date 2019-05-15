class Solution {
public:
    int n;
    vector<long long> pw;
    const int M = 1e9 + 7;
    
    int find(const string& s, int l) {
        unordered_map<long long, vector<int>> pos;
        long long h = 0;
        for (int i=0; i<n; ++i) {
            if (i >= l)
                h = ((h - (s[i-l]-'a'+1)*pw[l-1]) % M + M) % M;
            h = (h * 2 + (s[i]-'a'+1)) % M;
       
            if (i >= l-1) {
                int p = i - l + 1;
                if (pos.count(h)) {
                    for (auto j : pos[h])        
                        if (equal(s.begin()+p, s.begin()+p+l, s.begin()+j))
                            return j;
                }
                pos[h].push_back(p);
            }       
        }
        return -1;
    }
    
    string longestDupSubstring(string s) {
        n = s.size();
        int l = 0, r = n - 1;
        
        pw.push_back(1);
        for (int i=1; i<=n; ++i) pw.push_back(pw.back()*2 % M);
        
        while (l < r) {
            int mid = (l+r+1) >> 1, p = find(s, mid);
            if (p == -1)
                r = mid - 1;
            else 
                l = mid;
        }
        if (l==0) 
            return "";
        else
            return s.substr(find(s, l), l);   
    }
};