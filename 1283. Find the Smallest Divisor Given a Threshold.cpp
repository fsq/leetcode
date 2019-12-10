class Solution {
public:
    int smallestDivisor(vector<int>& a, int threshold) {
        int l=1, r=1000000;
        while (l < r) {
            int mid = (l+r) >> 1;
            int ans = 0;
            for (auto x : a)
                ans += (x + mid -1) / mid;
            if (ans > threshold)
                l = mid + 1;
            else 
                r = mid;
        }
        return l;
    }
};