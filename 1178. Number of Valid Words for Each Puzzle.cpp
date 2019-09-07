class Solution {
public:
    unordered_map<int, int> m;
    
    void dfs(const string& s, int i, int& cnt, int x) {
        if (i==s.size()) {
            if (m.count(x)) 
                cnt += m[x];        
        } else {
            dfs(s, i+1, cnt, x);
            x |= 1 << (s[i] - 'a');
            dfs(s, i+1, cnt, x);
        }
    }
    
    vector<int> findNumOfValidWords(vector<string>& w, vector<string>& p) {
        for (auto& s : w) {
            unordered_set<char> st(s.begin(), s.end());
            int x = 0;
            for (auto c : st)
                x |= 1 << (c-'a');
            ++m[x];
        }
        
        vector<int> ans;
        for (auto& s : p) {
            int cnt = 0;
            dfs(s, 1, cnt, 1<<(s[0]-'a'));
            ans.push_back(cnt);
        }
        return ans;
    }
};