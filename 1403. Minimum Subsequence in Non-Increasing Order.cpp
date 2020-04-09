class Solution {
public:
    vector<int> minSubsequence(vector<int>& a) {
        sort(a.rbegin(), a.rend());
        int sum = accumulate(a.begin(), a.end(), 0), cur = 0;
        vector<int> ans;
        for (auto x : a) {
            ans.push_back(x);
            cur += x;
            if (cur > sum-cur) break;
        }
        return ans;
    }
};