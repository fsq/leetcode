class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<int> ind(n+1);
        unordered_set<string> st;
        for (auto& pr : edges) {
            ++ind[pr[0]];
            ++ind[pr[1]];
            st.insert(to_string(pr[0])+","+to_string(pr[1]));
            st.insert(to_string(pr[1])+","+to_string(pr[0]));
        }
        vector<int> s;
        for (int i=1; i<=n; ++i)
            if (ind[i] & 1)
                s.push_back(i);
        
        auto ok = [&](int x, int y) {
            return !st.count(to_string(x) + "," + to_string(y));
        };
        if (s.size() == 0) return true;
        if (s.size()==2) {
            if (ok(s[0], s[1])) return true;
            for (int i=1; i<=n; ++i)
                if (i!=s[0] && i!=s[1] && ok(s[0], i) && ok(s[1], i))
                    return true;
        } else if (s.size()==4) {
            if((ok(s[0], s[1]) && ok(s[2], s[3])) || 
                (ok(s[0], s[2]) && ok(s[1], s[3])) ||
                (ok(s[0], s[3]) && ok(s[1], s[2])))
                return true;
        }
        return false;
    }
};