class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int, int> p;
        for (auto& l : logs) {
            ++p[l[0]];
            --p[l[1]];
        }
        int ans = -1, mx = 0, tot = 0;
        for (auto& pr : p) {
            tot += pr.second;
            if (tot > mx) {
                ans = pr.first;
                mx = tot;
            }
        }
        return ans;
    }
};