class Solution {
public:
    int distanceBetweenBusStops(vector<int>& a, int x, int y) {
        if (x > y) swap(x, y);
        int s = accumulate(a.begin(), a.end(), 0);
        int d = accumulate(a.begin()+x, a.begin()+y, 0);
        return min(d, s-d);
    }
};