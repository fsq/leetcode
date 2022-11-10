class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        vector<int> pre(26);
        for (auto& w : words) {
            vector<int> now(26);
            for (auto c : w) ++now[c-'a'];
            if (pre != now) {
                pre = std::move(now);    
                ans.push_back(w);
            }
        }
        return ans;
    }
};