class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n+1);
        for (auto& b : bookings) {
            ans[b[0]-1] += b[2];
            ans[b[1]] -= b[2];
        }
        partial_sum(ans.begin(), ans.end(), ans.begin());
        ans.pop_back();
        return ans;
    }
};