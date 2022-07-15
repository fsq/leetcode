class Solution {
public:
    const int M = 1e9 + 7;
    int numberOfWays(string a) {
        long long ans = 1;
        int pre_bar = 0, pre_s = -1, cnt_s = 0;
        for (int i=0; i<a.size(); ++i)
            if (a[i] == 'S') {
                ++cnt_s;
                if (pre_s == -1) {
                    pre_s = i;
                    if (pre_bar > 0)
                        ans = ans * (i - pre_bar + 1) % M;
                } else {
                    pre_s = -1;
                    pre_bar = i+1;
                }
            }
        return cnt_s>=2 && !(cnt_s&1) ? ans : 0;
    }
};