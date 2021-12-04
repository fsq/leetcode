class Solution {
public:
    int minimumDifference(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int mind = INT_MAX;
        for (int i=0; i+k<=a.size(); ++i)
            mind = min(mind, a[i+k-1]-a[i]);
        return mind;
    }
};