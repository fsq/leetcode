class Solution {
public:
    int wateringPlants(vector<int>& a, int capacity) {
        int ans = 0, r = capacity;
        for (int i=0; i<a.size(); ++i) {
            if (a[i] > r) {
                ans += i * 2;
                r = capacity;
            }
            ++ans;
            r -= a[i];
        }
        return ans;
    }
};