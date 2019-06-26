class Solution {
public:
    
    void insert(unordered_set<string>& a, unordered_set<string>& b) {
        for (auto& s : b)
            a.insert(move(s));
        b.clear();
    }
    
    void merge(unordered_set<string>& a, unordered_set<string>& b) {
        if (a.empty())
            swap(a, b);
        else {
            unordered_set<string> s;
            for (auto& x : a) 
                for (auto& y : b) 
                    s.insert(x+y);
            a.swap(s);
        }
    }
    
    unordered_set<string> dfs(const string& s, int& i) {            
        if (s[i] != '{')
            return {string(1, s[i++])};
        unordered_set<string> st, carry;
        ++i;
        while (i<s.size() && s[i]!='}') {
            auto f = dfs(s, i);
            merge(carry, f);
            if (s[i]==',') {
                ++i;
                insert(st, carry);
            }
        }
        insert(st, carry);
        ++i;
        return st;
    }
    
    vector<string> braceExpansionII(string s) {
        int i = 0;
        s = "{" + s + "}";
        auto st = dfs(s, i);
        vector<string> ans(st.begin(), st.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};