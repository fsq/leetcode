class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& a, int e) {
        int mx = *max_element(a.begin(), a.end());
        vector<bool> ans;
        for (auto x : a)
            ans.push_back(x+e >= mx);
        return ans;
    }
};