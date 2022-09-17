class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end()); 
        a.resize(unique(a.begin(), a.end()) - a.begin());
        sort(b.begin(), b.end()); 
        b.resize(unique(b.begin(), b.end()) - b.begin());
        vector<int> ans1, ans2;
        set_difference(a.begin(), a.end(), b.begin(), b.end(), back_inserter(ans1));
        set_difference(b.begin(), b.end(), a.begin(), a.end(), back_inserter(ans2));
        return {ans1, ans2};
    }
};