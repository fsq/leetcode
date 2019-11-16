class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& a) {
        int n = a.size();
        vector<vector<int>> s(2, vector<int>(n));
        for (int i=0; i<n; ++i)
            if (a[i] == 2) {
                if (!upper || !lower) return {};
                --upper, --lower;
                s[0][i] = s[1][i] = 1;    
            }
        for (int i=0; i<n; ++i) 
            if (a[i] == 1) {
                if (upper) {
                    s[0][i] = 1;
                    --upper;
                } else if (lower) {
                    s[1][i] = 1;
                    --lower;
                } else 
                    return {};
            }
        
        if (upper || lower) return {};
        return s;
    }
};