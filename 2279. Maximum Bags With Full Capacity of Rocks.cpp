class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int r) {
        for (int i=0; i<rocks.size(); ++i)
            rocks[i] = capacity[i] - rocks[i];
        sort(rocks.begin(), rocks.end());
        int ans = 0;
        for (auto x : rocks)
            if (x > r)
                break;
            else {
                ++ans;
                r -= x;
            }
        return ans;
    }
};