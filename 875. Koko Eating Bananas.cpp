class Solution {
public:
    int minEatingSpeed(vector<int>& a, int H) {
        int l = 1, r = 1e9;
        while (l < r) {
            int mid = (l+r) >> 1;
            int ans = 0;
            for (auto x : a) 
                ans += (x+mid-1) / mid;
            if (ans > H)
                l = mid + 1;
            else 
                r = mid;
        }
        return l;
    }
};