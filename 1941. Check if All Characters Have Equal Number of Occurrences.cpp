class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> m;
        for (auto c : s) ++m[c];
        auto it = m.begin();
        int x = m.begin()->second;
        while (it != m.end()) {
            if (it->second != x) return false;
            it = next(it);
        }
        return true;
    }
};