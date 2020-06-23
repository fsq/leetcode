class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> cnt;
        vector<string> ans;
        for (auto s : names) {
            string res = s;
            while (cnt.count(res)) {
                res  = s + "(" + to_string(cnt[s]++) + ")";
            }
            ++cnt[res];
            ans.push_back(res);
        }
        return ans;
    }
};