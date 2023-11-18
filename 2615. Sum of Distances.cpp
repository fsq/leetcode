class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, int> p, ind;
        unordered_map<int, pair<long long, long long>> sum;
        for (int i=0; i<nums.size(); ++i) {
            ++p[nums[i]];
            sum[nums[i]].second += i;
        }
        vector<long long> ans;
        for (int i=0; i<nums.size(); ++i) {
            int x = nums[i];
            long long &pre = sum[x].first, &nxt = sum[x].second;
            nxt -= i;
            long long after = p[x] - ind[x] - 1, before = ind[x];
            ans.push_back((nxt-after*i) + (before*i-pre));
            ++ind[x];
            pre += i;
        }
        return ans;
    }
};