//https://leetcode.com/problems/next-greater-element-i/description/
class Solution {
public:
    // O(n+m) time
    // O(n+m) space
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> ans(findNums.size(), -1);
        unordered_map<int, int> map;
        
        for (int i=0; i<findNums.size(); ++i)
            map[findNums[i]] = i;
        
        // maintain a monotonically non-increasing sequence
        stack<int> stk;
        for (auto x : nums) {
            while (!stk.empty() && x > stk.top()) {
                // when top is popped, its next greater element is x
                if (map.find(stk.top()) != map.end())
                    ans[map[stk.top()]] = x;
                stk.pop();
            }
            stk.push(x);
        }
        return ans;
    }
};