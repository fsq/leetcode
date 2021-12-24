class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<string, long long> cnt;
        for (auto& r : rectangles) {
            int g = __gcd(r[0], r[1]);
            string h = to_string(r[0]/g) + "," + to_string(r[1]/g);
            ++cnt[h];
        }
        long long ans = 0;
        for (auto& g : cnt) 
            ans += g.second * (g.second-1) / 2;
        return ans;
    }
};