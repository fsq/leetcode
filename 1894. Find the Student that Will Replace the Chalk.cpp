class Solution {
public:
    int chalkReplacer(vector<int>& a, int k) {
        long long s = accumulate(a.begin(), a.end(), 0ll);
        k %= s;
        for (int i=0; i<a.size(); ++i)
            if (a[i] > k) 
                return i;
            else
                k -= a[i];
        return 0;
    }
};