class Solution {
public:
    int mostWordsFound(vector<string>& a) {
        int ans = 0;
        for (auto& s : a)
            ans = max<int>(ans, count(s.begin(), s.end(), ' ') + 1);
        return ans;
    }
};