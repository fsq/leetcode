class Solution {
public:
    bool isTransformable(string s, string t) {
        vector<stack<int>> p(10);
        vector<int> cnt(10);
        int n = s.size();
        for (int i=n-1; i>=0; --i) {
            ++cnt[t[i]-'0'];
            p[s[i]-'0'].push(i);
        }
        for (int i=0; i<10; ++i)
            if (cnt[i] != p[i].size())
                return false;
        
        for (auto c : t) {
            int x = c - '0', nxt = p[x].top();
            for (int j=0; j<x; ++j)
                if (p[j].size() && p[j].top() < nxt) return false;
            p[x].pop();
        }
        return true;
    }
};