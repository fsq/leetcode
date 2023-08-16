class Solution {
public:
    long long minOperations(vector<int>& a, vector<int>& b, int k) {
        long long ans = 0, sum = 0;
        for (int i=0; i<a.size(); ++i) {
            long long diff = a[i] - b[i];
            if (k) {
                if (diff % k) return -1;
                sum += diff;
                ans += abs(diff) / k;
            } else {
                if (diff) return -1;
            }
        }
        if (sum != 0) return -1;
        return ans / 2;
    }
};