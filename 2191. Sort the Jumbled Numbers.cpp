class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        auto trans = [&](int x) {
            string s = to_string(x);
            for (auto& c : s)
                c = mapping[c-'0'] + '0';
            return stoi(s);
        };
        
        unordered_map<int, int> m;
        for (auto x : nums) 
            if (!m.count(x))
                m[x] = trans(x);
        
        stable_sort(nums.begin(), nums.end(), [&](int x, int y) {
            return m[x] < m[y];
        });
        return nums;
    }
};