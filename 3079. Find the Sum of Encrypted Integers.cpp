class Solution {
public:
    int sumOfEncryptedInt(vector<int>& a) {
        int ans = 0;
        for (auto x : a) {
            auto s = to_string(x);
            char c = *max_element(s.begin(), s.end());
            int y = stoi(string(s.size(), c));
            ans += y;
        }
        return ans;
    }
};