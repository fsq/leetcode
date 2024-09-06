class Solution {
public:
    int sumCounts(vector<int>& a) {
        int ans = 0;
        for (int i=0; i<a.size(); ++i)
            for (int j=i; j<a.size(); ++j) {
                int d = unordered_set<int>(a.begin()+i, a.begin()+j+1).size();
                ans += d * d;
            }
        return ans;
    }
};