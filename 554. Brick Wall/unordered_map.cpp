class Solution {
public:
    // https://leetcode.com/problems/brick-wall/description/
    // unordered_map O(n) solution
    
    int leastBricks(vector<vector<int>>& wall) {
        int height = wall.size();
        unordered_map<int, int> count;
        int width, ans = height;
        for (const auto& row : wall) {
            width = 0;
            for (int i=0; i+1<row.size(); ++i) 
                ++count[width += row[i]];
        }
        
        for (const auto& kv : count) 
            ans = min(ans, height-kv.second);
        
        return ans;
    }
};