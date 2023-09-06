class Solution {
public:
    int maxCount(vector<int>& ban, int n, int maxSum) {
        sort(ban.begin(), ban.end());
        ban.resize(unique(ban.begin(), ban.end()) - ban.begin());
        int cnt = 0, i = 0, x = 1, sum = 0;
        for (int x=1; x<=n && sum+x<=maxSum; ++x) {
            if (i<ban.size() && ban[i]==x) {
                ++i;
            } else {
                sum += x;
                ++cnt;
            }
        }
        return cnt;
    }
};