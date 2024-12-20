class Solution {
public:
    int longestCommonPrefix(vector<int>& a, vector<int>& b) {
        unordered_set<string> sa, sb;
        for (auto& v : a) {
            auto s = to_string(v);
            string f;
            for (auto c : s) {
                f.push_back(c);
                sa.insert(f);
            }
        }
        for (auto& v : b) {
            auto s = to_string(v);
            string f;
            for (auto c : s) {
                f.push_back(c);
                sb.insert(f);
            }
        }
        unordered_set<string> ans = {""}, nxt;
        int ret = 0;
        do {
            nxt.clear();
            ret = ans.begin()->size();
            for (auto& s : ans) {
                for (auto c='0'; c<='9'; ++c) {
                    auto t = s + c;
                    if (sa.count(t) && sb.count(t))
                        nxt.insert(t);
                }
            }
            ans = nxt;
        } while (ans.size() > 0);
        return ret;      
    }
};