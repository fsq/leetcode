class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> f(6, 1); 
        f[0] = 0;
        for (int i=1; i<n; ++i) 
            for (int j=2; j<=5; ++j)
                f[j] += f[j-1];
        return accumulate(f.begin(), f.end(), 0);
    }
};