class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<int> a(names.size());
        iota(a.begin(), a.end(), 0);

        sort(a.begin(), a.end(), [&](int x, int y) {
            return heights[x] > heights[y];
        });
        vector<string> ans;
        for (auto x : a) ans.push_back(names[x]);
        return ans;
    }
};