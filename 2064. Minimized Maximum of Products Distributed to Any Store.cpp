class Solution {
public:
    
    int put(vector<int>& a, int x) {
        int ans = 0;
        for (auto c : a) {
            ans += (c + x-1) /x;
        }
        return ans;
    }
    
    int minimizedMaximum(int n, vector<int>& a) {
        long long l = 1, r = 10000000000;
        while (l < r) {
            long long mid = (l + r) >> 1;
            if (put(a, mid) > n) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};