class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& a, vector<string>& b) {
        return accumulate(a.begin(), a.end(), string("")) == accumulate(b.begin(), b.end(), string(""));
    }
};