class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = left.size() ? *max_element(left.begin(), left.end()) : 0;
        for (auto x : right) ans = max(ans, n - x);
        return ans;
    }
};