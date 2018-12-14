class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> map(128);
        for (int i=0; i<26; ++i)
            map[order[i]] = i + 'a';
        for (auto& s : words)
            for (auto &c : s)
                c = map[c];
        return is_sorted(words.begin(), words.end());
    }
};