class Solution {
public:

    int maxTotalReward(vector<int>& a) {
        sort(a.begin(), a.end());
        bitset<100001> b;
        bitset<100001> m;
        b[0] = true;
        int i = 0;
        int ans = 0;
        for (auto x : a) {
            while (i < x) {
                m[i] = true;
                ++i;
            }
            b = b | ((b & m) << x);
        }
        for (int i=a.back()*2; i>=0; --i)
            if (b[i])
                return i;
        return 0;
    }
};