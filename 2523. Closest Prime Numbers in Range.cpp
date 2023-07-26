class Solution {
public:

    bool isPrime(int x) {
        for (int i=2; i*i<=x; ++i) 
            if (x % i == 0)
                return false;
        return true;
    }

    vector<int> closestPrimes(int left, int right) {
        int pre = -1, ans = INT_MAX;
        vector<int> pr;
        for (auto x=max(2,left); x<=right; ++x) 
            if (isPrime(x)) {
                if (pre != -1 && x-pre < ans) {
                    ans = x - pre;
                    pr = {pre, x};
                }
                pre = x;
            }
        return ans==INT_MAX ? vector<int>(2, -1) : pr;
    }
};