class Solution {
public:
    
    int f[2003][2003];
    
    bool pan(string& s, int l, int r) {
        if (l==r) return true;
        if (l+1==r) return s[l]==s[r];
        
        if (f[l][r] != -1) return f[l][r];
        return f[l][r] = s[l]==s[r] && pan(s, l+1, r-1);
    }
    
    bool checkPartitioning(string s) {
        memset(f, -1, sizeof(f));
        
        for (int i=1; i+1<s.size(); ++i)
            for (int j=i+1; j<s.size(); ++j)
                if (pan(s, 0, i-1) && pan(s, i, j-1) && pan(s, j, s.size()-1))
                    return true;
        return false;
    }
};