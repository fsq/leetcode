class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& a, string s) {
        sort(a.begin(), a.end());
        vector<vector<string>> ans;
        vector<string> cur(a);
        for (int i=0; i<s.size(); ++i) {
            vector<string> nxt;
            for (auto& w : cur)
                if (w[i] == s[i])
                    nxt.push_back(move(w));
            cur.swap(nxt);
            vector<string> sub;
            for (int i=0; i<min<int>(3, cur.size()); ++i) sub.push_back(cur[i]);
            ans.push_back(move(sub));
        }
        return ans;
    }
};