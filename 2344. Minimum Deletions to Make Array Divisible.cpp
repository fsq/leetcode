class Solution {
public:
    int minOperations(vector<int>& a, vector<int>& b) {
        int g = b[0];
        for (auto x : b) g = __gcd(g, x);
        sort(a.begin(), a.end());
        for (int i=0; i<a.size() && a[i]<=g; ++i)
            if (g%a[i] == 0)
                return i;
        return -1;
    }
};