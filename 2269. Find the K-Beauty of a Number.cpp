class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int ans = 0;
        auto s = to_string(num);
        for (int i=0; i+k<=s.size(); ++i) {
            auto t = stoi(s.substr(i, k));
            if (t != 0 && num % t == 0)
                ++ans;
        }
        return ans;
    }
};