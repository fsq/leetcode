class Solution {
public:
    vector<int> decode(vector<int>& a, int x) {
        vector<int> ans = {x};
        for (auto y : a)
            ans.push_back(ans.back() ^ y);
        return ans;
    }
};