class Solution {
public:
    int maxNumberOfBalloons(string s) {
        unordered_map<char, int> m;
        for (auto c : s) ++m[c];
        int ans = INT_MAX;
        string once="ban", tw="lo";
        for (auto c : once) ans = min(ans, m[c]); 
        for (auto c : tw) ans = min(ans, m[c]/2);
        return ans;
    }
};