class Solution {
public:
    
    int ans = 0;
    
    bool ispan(string& s) {
        if (s.empty()) return false;
        for (int i=0, j=s.size()-1; i<j; ++i, --j)
            if (s[i] != s[j])
                return false;
        return true;
    }
    
    void dfs(string& s, string& a, string& b, int i) {
        if (i==s.size()) {
            if (ispan(a) && ispan(b))
                ans = max<int>(ans, a.size() * b.size());
        } else {
            a.push_back(s[i]);
            dfs(s, a, b, i+1);
            a.pop_back();
            
            b.push_back(s[i]);
            dfs(s, a, b, i+1);
            b.pop_back();
            
            dfs(s, a, b, i+1);
        }
    }
    
    int maxProduct(string s) {
        string a, b;
        dfs(s, a, b, 0);
        return ans;
    }
};