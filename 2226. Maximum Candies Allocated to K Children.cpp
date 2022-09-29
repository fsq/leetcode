class Solution {
public:
    int maximumCandies(vector<int>& a, long long k) {
        long long sum = accumulate(a.begin(), a.end(), 0ll);
        if (sum < k) return 0;
        long long l=1, r=sum/k;
        while (l < r) {
            long long m = (l+r+1) >> 1, x = 0;
            for (auto y : a) x += y/m;
            if (x >= k) 
                l = m;
            else 
                r = m-1;
        }
        return l;
    }
};