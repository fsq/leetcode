class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string s, int k) {
        unordered_map<string, int> m;
        int mx = 0;
        for (int i=0; i<s.size(); i+=k)
            mx = max(mx, ++m[s.substr(i, k)]);
        return s.size()/k-mx;
    }
};