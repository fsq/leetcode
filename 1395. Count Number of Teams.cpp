class Solution {
public:
    
    int solve(vector<int> a) {
        int n = a.size(), ans = 0;
        vector<int> s(n);
        for (int i=1; i<n; ++i) {
            for (int j=0; j<i; ++j)
                if (a[j] < a[i]) {
                    ++s[i];
                    ans += s[j];
                }
        }
        return ans;
    }
    
    int numTeams(vector<int>& a) {
        return solve(a) + solve(vector<int>(a.rbegin(), a.rend()));
    }
};