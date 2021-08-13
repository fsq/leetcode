class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> cnt(26);
        for (auto& s : words)
            for (auto c : s)
                ++cnt[c-'a'];
        for (auto x : cnt)
            if (x % words.size() != 0)
                return false;
        return true;
    }
};