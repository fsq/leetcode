class Solution {
public:
    int kthLargestValue(vector<vector<int>>& a, int k) {
        int ans = 0;
        multiset<int, std::greater<int>> q;
        for (int i=0; i<a.size(); ++i)
            for (int j=0; j<a[0].size(); ++j) {
                int x = a[i][j];
                if (i > 0) x ^= a[i-1][j];
                if (j > 0) x ^= a[i][j-1];
                if (i > 0 && j > 0) x ^= a[i-1][j-1];
                a[i][j] = x;
                if (q.size()==k && x<=*prev(q.end())) continue;
                q.insert(x);
                if (q.size() > k) {
                    q.erase(prev(q.end()));
                }
            }
        return *prev(q.end());
    }
};