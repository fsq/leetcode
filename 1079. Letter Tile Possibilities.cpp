class Solution {
public:
    unordered_set<string> st;
    
    void dfs(string& a, string& s, int i) {
        st.insert(s);            
        if (i==a.size())
            return;
        else {
            for (int j=0; j<a.size(); ++j)
                if (a[j] != ' ') {
                    s.push_back(a[j]);
                    auto t = a[j];
                    a[j] = ' ';
                    dfs(a, s, i+1);
                    s.pop_back();
                    a[j] = t;
                }
        }
    }
    
    int numTilePossibilities(string tiles) {
        string s;
        dfs(tiles, s, 0);
        return st.size() - 1;
    }
};