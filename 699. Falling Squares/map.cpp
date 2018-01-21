class Solution {
public:
    
    // https://leetcode.com/problems/falling-squares/description/
    // map O(nlogn) time O(n) space solution
    // since we at most add O(n) edges and delete O(n) edges
    // for each square we use O(logn) time to find squares under it
    
    vector<int> fallingSquares(vector<pair<int, int>>& positions) {
        map<int, int> height;  // height[x] : height to the right of x
        vector<int> ans;
        int highest = 0;
        for (auto &sqr : positions) {
            int max_h = 0, x = sqr.first, len = sqr.second, r_height = 0;
            auto under = height.upper_bound(x);

            // the nearest height to the left
            if (under != height.begin()) 
                r_height = max_h = prev(under, 1)->second;
            
            for (; under!=height.end() && under->first<x+len; ) {
                r_height = under->second;
                max_h = max(max_h, under->second);
                ++under;
                height.erase(prev(under, 1));
            }
            
            highest = max(highest, max_h+len);
            ans.push_back(highest);
            
            height[x] = max_h + len;
            if (height.find(x+len)==height.end())
                height[x+len] = r_height;
        }
        return ans;
    }
};