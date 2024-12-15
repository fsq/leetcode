class Solution {
public:
    int minOrAfterOperations(vector<int>& a, int k) {
        int ans = 0;
        for (auto x : a) ans |= x;
        int rm = 0;
        for (int bt=29; bt>=0; --bt) {
            rm |= 1 << bt;
            int cnt = 0, cur = -1;
            for (auto x : a) {
                if (cur == -1) {
                    if (x & rm) cur = x & rm;
                } else {
                    cur &= x;
                    ++cnt;
                    if (cur == 0) {
                        cur = -1;
                    }
                }
            }
            if (cur != -1) ++cnt;
            if (cnt>0 && cnt<=k) {
                ans &= ~(1<<bt);
                // std::cout << std::bitset<32>(ans) << std::endl;
            } else {
                rm ^= 1 << bt;
            }
        }
        return ans;
    }
};