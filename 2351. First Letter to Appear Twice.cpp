class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> a(26);
        for (auto c : s)
            if (++a[c-'a']==2)
                return c;
        return 0;
    }
};