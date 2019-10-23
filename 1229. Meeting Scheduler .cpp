class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& a, vector<vector<int>>& b, int duration) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for (int i=0,j=0; i<a.size() && j<b.size(); ) {
            int r = min(a[i][1], b[j][1]), l = max(a[i][0], b[j][0]);
            if (r-l >= duration) 
                return {l, l+duration};
            else if (a[i][0] < b[j][0])
                ++i;
            else 
                ++j;
        }
        return {};
    }
};