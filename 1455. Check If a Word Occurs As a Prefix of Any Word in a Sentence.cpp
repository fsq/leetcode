class Solution {
public:
    int isPrefixOfWord(string sentence, string a) {
        istringstream sin(sentence);
        string w;
        int id = 1;
        while (sin >> w) {
            if (w.substr(0, a.size()) == a)
                return id;
            ++id;
        }
        return -1;
    }
};