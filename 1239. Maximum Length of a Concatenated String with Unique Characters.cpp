class Solution {
public:
    
    int ans = 0;
    
    void dfs(vector<string>& s, vector<int>& a, int m, int i, int len) {
        if (i==a.size()) {
            ans = max(ans, len);
        } else {
            dfs(s, a, m, i+1, len);
            if ((a[i] & m) == 0)
                dfs(s, a, m|a[i], i+1, len+s[i].size());
        }
    }
    
    int maxLength(vector<string>& arr) {
        vector<int> a;
        vector<string> str;
        for (auto s : arr) {
            int b = 0;
            bool ok = true;
            for (auto c : s) 
                if ((b>>(c-'a')) & 1) {
                    ok = false;
                    break;
                } else
                    b |= 1 << (c-'a');
            if (ok) {
                a.push_back(b);
                str.push_back(s);
            }
        }
        
        dfs(str, a, 0, 0, 0);
        
        return ans;
    }
};