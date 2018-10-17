class Solution {
public:
    vector<string> wordSubsets(vector<string>& a, vector<string>& b) {
        vector<int> mask(26);
        for (auto& s : b) {
            vector<int> now(26);
            for (auto c : s)
                ++now[c-'a'];
            for (int i=0; i<26; ++i)
                mask[i] = max(mask[i], now[i]);
        }
        
        vector<string> ans;
        for (auto& s : a) {
            vector<int> now(26);
            for (auto c : s)
                ++now[c-'a'];
            bool ok = true;
            for (int i=0; i<26; ++i)
                if (now[i]<mask[i]) {
                    ok = false;
                    break;
                }
            if (ok)
                ans.push_back(s);
        }
        return ans;
    }
};