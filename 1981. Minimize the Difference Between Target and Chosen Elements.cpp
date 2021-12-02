class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& a, int target) {
        int minsum = 0;
        for (auto& r : a)
            minsum += *min_element(r.begin(), r.end());
        if (minsum > target) return minsum - target;
        bitset<871> bs;
        bs[0] = true;
        for (int i=0; i<a.size(); ++i) {
            bitset<871> row;
            for (auto x : a[i])
                row |= bs << x;
            bs = row;
        }
        int dis = INT_MAX;
        for (int i=0; i<bs.size(); ++i)
            if (bs[i] && abs(i-target)<dis) {
                dis = abs(i - target);
            }
        return dis;
    }
};