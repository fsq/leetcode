class Solution {
public:
    
    unordered_map<int, int> f;
    
    int minDays(int n) {
        if (n<=1) return 1;
        if (!f.count(n)) {
            f[n] = min(minDays(n/3) + n%3, minDays(n/2) + n%2) + 1;
        }
        return f[n];
    }
};