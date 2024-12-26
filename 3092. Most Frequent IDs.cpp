class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        multiset<long long, std::greater<long long>> st;
        unordered_map<int, long long> m;
        vector<long long> ans;
        for (int i=0; i<nums.size(); ++i) {
            if (m.count(nums[i]))
                st.erase(st.find(m[nums[i]]));
            m[nums[i]] += freq[i];
            st.insert(m[nums[i]]);
            ans.push_back(*st.begin());
        }
        return ans;
    }
};