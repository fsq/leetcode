class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n==0) return 0;
        vector<int> a(n+1);
        a[1] = 1;
        for (int i=2; i<=n; ++i) 
            if (i & 1)
                a[i] = a[i>>1] + a[(i>>1)+1];
            else 
                a[i] = a[i>>1];
        return *max_element(a.begin(), a.end());
    }
};