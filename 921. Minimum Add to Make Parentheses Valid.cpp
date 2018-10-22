class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0, sum = 0;
        for (auto c : s) {
            sum += c=='(' ? 1 : -1;
            if (sum<0)
                ++ans, ++sum;
        }
        ans += sum;
        return ans;
    }
};