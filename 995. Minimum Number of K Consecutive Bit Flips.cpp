class Solution {
public:
    int minKBitFlips(vector<int>& a, int k) {
        int n = a.size(), ans = 0;
        for (int cnt=0, i=0; i<n; ++i) {
            if (i>=k) cnt ^= a[i-k];
            if (!(cnt ^ a[i])) {
                if (i+k>n) return -1;
                ++ans;
                cnt ^= 1;
                a[i] = 1;
            } else 
                a[i] = 0;
        }
        return ans;
    }
};