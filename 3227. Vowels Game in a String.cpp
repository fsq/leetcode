class Solution {
public:
    bool doesAliceWin(string s) {
        int v = 0;
        string vs = "aeiou";
        for (auto c : s)
            if (vs.find(c) != string::npos)
                ++v;
        return v != 0;
    }
};