class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        for (int x=left; x<=right; ++x)
            if (!any_of(ranges.begin(), ranges.end(), [&](vector<int>& a) {
                return x>=a[0] && x<=a[1];
            })) {
                return false;
            }
        return true;
    }
};