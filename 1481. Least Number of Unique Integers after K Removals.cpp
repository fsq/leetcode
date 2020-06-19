class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& a, int k) {
        unordered_map<int, int> m;
        for (auto x : a) ++m[x];
        vector<int> s;
        for (auto& p : m) s.push_back(p.second);
        sort(s.begin(), s.end());
        int i = 0;
        while (k > 0 && i < s.size()) {
            int use = min<int>(k, s[i]);
            s[i] -= use;
            k -= use;
            if (s[i]==0) ++i;
        }
        return s.size() - i;
    }
};