class Solution {
public:
    bool isCircularSentence(string sentence) {
        istringstream sin(sentence);
        string first, s, pre;
        while (sin >> s) {
            if (first.empty()) {
                first = pre = s;
            } else {
                if (pre.back() != s.front()) return false;
                pre = s;
            }
        }
        return pre.back() == first.front();
    }
};