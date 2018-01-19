class Solution {
public:
    
    // https://leetcode.com/problems/maximum-vacation-days/description/
    // O(n^2 + k|E|) time O(n) space DP solution
    // f[i][j] = max(f[i-1][k]+days[k][i]), where flights[k][j]==1
    
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = flights.size();
        vector<vector<int>> edges(n, vector<int>{});
        for (int i=0; i<n; ++i) 
            for (int j=0; j<n; ++j)
                if (i==j || flights[i][j]==1)
                    edges[j].push_back(i);
        
        vector<int> cache(n, INT_MIN), f = cache;
        cache[0] = 0;
        
        for (int steps=0; steps<days[0].size(); ++steps) {
            fill(f.begin(), f.end(), INT_MIN);
            for (int i=0; i<n; ++i) 
                for (auto prev : edges[i]) 
                    f[i] = max(f[i], cache[prev]+days[i][steps]);
            f.swap(cache);
        }
        
        return *max_element(cache.begin(), cache.end());
                
    }
};