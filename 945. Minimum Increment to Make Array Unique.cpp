class Solution {
public:
    int minIncrementForUnique(vector<int>& a) {
        if (a.empty()) return 0;
        sort(a.begin(), a.end());
        int base = a[0];
        int sum = 0;
        for (auto x : a) 
            if (x<=base) {
                sum += base - x;
                ++base;
            } else 
                base = x + 1;
        return sum;
    }
};