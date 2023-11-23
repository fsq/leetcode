class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> ans;
        long long mx = 0;
        for (auto x : nums) {
            mx = max<long long>(mx , x);
            ans.push_back(x + (ans.size()==0 ? mx : ans.back()+mx));
        }
        return ans;
    }
};