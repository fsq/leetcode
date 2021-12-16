class Solution {
public:
    
    const int M = 1e9 + 7;
    
    int firstDayBeenInAllRooms(vector<int>& a) {
        int n = a.size();
        vector<int> reach(n), back(n);
        reach[0] = 0;
        back[0] = 1;
        for (int i=1; i<n; ++i) {
            reach[i] = (reach[i-1] + back[i-1] + 1) % M;
            back[i] = a[i]==i ? 1:
                (1 + reach[i] - reach[a[i]] + M) % M;
        }
        return reach.back();
    }
};