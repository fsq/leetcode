class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& a) {
        unordered_map<string, unordered_set<int>> m;
        for (int k=0; k<a.size(); ++k) {
            string& s = a[k];
            for (int i=0; i<s.size(); ++i)
                for (int j=i; j<s.size(); ++j)
                    m[s.substr(i, j-i+1)].insert(k);
        }
        vector<string> ans;
        for (auto& s : a) {
            bool found = false;
            string ret;
            for (int l=1; !found && l<=s.size(); ++l) {
                for (int i=0; i+l<=s.size(); ++i) {
                    string t = s.substr(i, l);
                    if (m[t].size()==1 && (ret.empty() || t<ret)) {
                        ret = t;
                        found = true;
                    }
                }
            }
            ans.push_back(ret);
        }
        return ans;
    }
};