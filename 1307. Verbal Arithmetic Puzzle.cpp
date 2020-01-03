class Solution {
public:
    
    int result = 0, mxlen = 0;
    vector<int> no0;
    void dfs(int r, int c, int sum, unordered_map<char,int>& m, vector<string>& w, string& res) {
        if (c == res.size()) {
            result = 1;
        } else if (r == w.size()) {
            int rm = sum % 10, ns = sum / 10;
            if (m.count(res[c])) {
                if (m[res[c]]!=rm) 
                    return;
                else
                    dfs(0, c+1, ns, m, w, res);                    
            } else {
                for (auto& pr : m) if (pr.second==rm) return;
                m[res[c]] = rm;
                dfs(0, c+1, ns, m, w, res);
                m.erase(res[c]);
            }
        } else {
            if (c >= w[r].size()) 
                dfs(r+1, c, sum, m, w, res);
            else if (m.count(w[r][c]))
                dfs(r+1, c, sum+m[w[r][c]], m, w, res);
            else {
                vector<int> ok(10, 1);
                for (auto& pr : m) ok[pr.second] = false;
                if (no0[w[r][c]-'A']) ok[0] = false;
                for (int i=0; i<10; ++i)
                    if (ok[i]) {
                        m[w[r][c]] = i;
                        dfs(r+1, c, sum+i, m, w, res);
                        if (result) return;
                    }
                m.erase(w[r][c]);
            }
        }
    }
    
    bool isSolvable(vector<string>& words, string res) {
        no0.resize(26);
        unordered_map<char, int> m;
        for (auto& s : words) {
            reverse(s.begin(), s.end());
            mxlen = max<int>(mxlen, s.size());
            no0[s.back()-'A'] = true;
        }
        reverse(res.begin(), res.end());
        if (!(res.size()==mxlen || res.size()==mxlen+1)) return false;
        dfs(0, 0, 0, m, words, res);
        return result==1 ? true : false;
    }
};