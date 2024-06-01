class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        vector<int> b(32);
        for (auto x : nums) {
            ++b[log2(x)];
        }
        int p = 0, ans = 0;

        for (int i=0; i<32; ++i)
            if (target & (1<<i)) {
                // cout << i << endl;
                while (p < i) {
                    if (b[p] >= 2) {
                        b[p+1] += b[p] / 2;
                        b[p] %= 2;
                    }
                    ++p;
                }

                if (b[p] > 0) {
                    --b[p];
                } else {
                    int y;
                    for (y=p; y<b.size() && b[y]==0; ++y) {
                        b[y] = 1;
                    }
                    if (y == b.size()) {
                        return -1;
                    }
                    --b[y];
                    ans += y - p;
                }
            }
        return ans;
    }
};