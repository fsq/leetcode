class Solution {
public:
    
    const int M = 1000000007;
    
    int maxProfit(vector<int>& a, int o) {
        sort(a.begin(), a.end(), std::greater<int>());
        long long ans = 0, c = 1;
        for (auto i=0; i<a.size(); ++i) {
            long long x = a[i];
            long long nxt = i+1==a.size() ? 0 : a[i+1];
            if ((x - nxt) * c <= o) {
                ans = (ans + (x + (nxt+1)) * (x-nxt) / 2 * c) % M;
                o -= (x - nxt) * c;
                ++c;
            } else {
                int take = o / c;
                ans = (ans + (x + (x-take+1)) * take / 2 * c) % M;
                ans = (ans + o % c * (x-take)) % M;
                break;
            }
        }
        return ans;
    }
};