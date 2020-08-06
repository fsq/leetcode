class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> a;
        for (auto& r : grid) {
            int tail = 0;
            for (int i=n-1; i>=0 && r[i]==0; --i) ++tail;
            a.push_back(tail);
        }
        int ans = 0;
        for (int j, i=0; i<n; ++i) {
            for (j=i; j<n; ++j)
                if (a[j] >= n-i-1) 
                    break;
            if (j==n) return -1;
            ans += j - i;
            a.erase(a.begin() + j);
            a.insert(a.begin() + i, 0);
        }
        return ans;
    }
};