class Solution {
public:
    
    int rev(int x) {
        if (x==0) return 0;
        string s = to_string(x);
        while (s.back()=='0') s.pop_back();
        reverse(s.begin(), s.end());
        return stoi(s);
    }
    
    int countNicePairs(vector<int>& nums) {
        unordered_map<long long, int> m;
        for (auto x : nums) 
            ++m[x-rev(x)];
        long long ans = 0;
        for (auto& pr : m) {
            long long c = pr.second;
            ans = (ans + c * (c-1) / 2) % 1000000007;
        }
        return ans;
    }
};