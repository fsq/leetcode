class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> cnt(100001);
        for (auto x : nums) ++cnt[x+50000];
        vector<int> ans;
        for (int i=0; i<cnt.size(); ++i)
            ans.insert(ans.end(), cnt[i], i-50000);
        return ans;
    }
};