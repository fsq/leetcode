class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        unordered_map<string, int> f;
        int l = s.size() / k;
        for (int i=0; i<s.size(); i+=l) f[s.substr(i, l)]++;
        for (int i=0; i<t.size(); i+=l) {
            auto it = f.find(t.substr(i, l));
            if (it == f.end() || it->second == 0)
                return false;
            it->second--;
        }
        return true;
    }
};
