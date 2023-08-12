class Solution {
public:
    long long countGood(vector<int>& a, int k) {
        unordered_map<int, int> c;
        long long pr = 0, ans = 0;
        for (int l=0, r=0; l<a.size(); ) {
            while (pr < k && r < a.size()) {
                auto& x = c[a[r]];
                ++r;
                pr += x;
                ++x;
            }
            if (pr >= k) 
                ans += a.size() - r + 1;
            else
                break;

            auto& x = c[a[l]];
            ++l;
            pr -= x - 1;
            --x;
        }
        return ans;
    }
};