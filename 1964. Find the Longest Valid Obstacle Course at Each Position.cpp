class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& a) {
        vector<int> h, ans;
        for (auto x : a) {
            auto i = upper_bound(h.begin(), h.end(), x) - h.begin();
            if (i == h.size()) {
                h.push_back(x);
            } else {
                h[i] = x;
            }
            ans.push_back(i+1);
        }
        return ans;
    }
};