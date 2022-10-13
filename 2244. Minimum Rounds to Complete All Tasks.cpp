class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> m;
        for (auto x : tasks) ++m[x];
        int ans = 0;
        for (auto& pr : m) 
            if (pr.second == 1) 
                return -1;
            else
                ans += (pr.second + 2) / 3;
        return ans;
    }
};