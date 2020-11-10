class Solution {
public:
    int minDeletions(string s) {
        vector<int> f(26);
        for (auto c : s) ++f[c-'a'];
        unordered_map<int, int> m;
        for (int i=0; i<26; ++i) 
            if (f[i])
                ++m[f[i]];
        int ans = 0;
        for (int f=s.size(); f>0; --f)
            if (m.count(f) && m[f]>1) {
                ans += m[f] - 1;
                m[f-1] += m[f] - 1;
            }
        return ans;
    }
};