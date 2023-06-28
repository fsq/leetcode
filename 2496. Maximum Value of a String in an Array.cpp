class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int ans = 0;
        for (auto& s : strs)
            if (all_of(s.begin(), s.end(), [](char c){return isdigit(c); })) {
                ans = max(ans, stoi(s));
            } else {
                ans = max<int>(ans, s.size());
            }
        return ans;
    }
};