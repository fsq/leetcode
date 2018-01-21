class Solution {
public:
    
    // https://leetcode.com/problems/daily-temperatures/description/
    // O(n) time O(n) space using stack
    // maintain an increasing sequence
    
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>> q;
        int n = temp.size();
        
        vector<int> ans(n, 0);
        for (int i=n-1; i>=0; --i) {
            while (!q.empty() && temp[i]>=q.top().first)
                q.pop();
            if (!q.empty()) ans[i] = q.top().second - i;
            q.push({temp[i], i});
        }
        return ans;
    }
};