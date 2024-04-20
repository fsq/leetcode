class Solution {
public:
    bool isV(char c) {
        const string vs = "aeiou";
        return vs.find(tolower(c)) != string::npos;
    }

    string sortVowels(string s) {
        unordered_map<char, int> m;
        for (auto c : s) 
            if (isV(c))
                ++m[c];
        string order = "AEIOUaeiou";
        int k = 0;
        for (auto& c : s)
            if (isV(c)) {
                while (m[order[k]]==0) ++k;
                c = order[k];
                --m[order[k]];
            }
        return s;
    }
};