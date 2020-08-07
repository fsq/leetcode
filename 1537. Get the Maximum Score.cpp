class Solution {
public:
    int maxSum(vector<int>& a, vector<int>& b) {
        a.push_back(INT_MAX), b.push_back(INT_MAX);
        vector<pair<int,int>> p;
        for (int i=0,j=0; i<a.size() && j<b.size(); ) 
            if (a[i] < b[j])
                ++i;
            else if (a[i] > b[j])
                ++j;
            else {
                p.push_back({i, j});
                ++i, ++j;
            }
        int i = 0, j = 0;
        long long ans = 0;
        for (auto& pr : p) {
            long long sa = 0, sb = 0;
            while (i<pr.first) sa += a[i++];
            while (j<pr.second) sb += b[j++];
            ans += max(sa, sb) + (a[pr.first]==INT_MAX ? 0 : a[pr.first]);
            i = pr.first + 1, j = pr.second + 1;
        }
        return ans % 1000000007;
    }
};