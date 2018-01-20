class Solution {
public:
    
    // https://leetcode.com/problems/maximum-average-subarray-ii/description/
    // O(n) solution 
    // using monotonical deque
    
    bool turn_right(const pair<int,int>& a, const pair<int,int>& b, const pair<int,int>& c) {
        int x1 = b.first-a.first, y1 = b.second-a.second;
        int x2 = c.first-a.first, y2 = c.second-a.second;
        return x1*y2 - x2*y1 <= 0;
    }
    
    double findMaxAverage(vector<int>& nums, int k) {
        deque<pair<int,int>> stk;
        
        nums.insert(nums.begin(), 0);
        int n = nums.size();
        vector<int> sum = {nums[0]};
        for (int i=1; i<n; ++i) sum.push_back(sum.back()+nums[i]);
        
        double ans = INT_MIN;
        for (int i=k; i<n; ++i) {
            auto nxt = pair<int,int>{i-k, sum[i-k]};
            while (stk.size()>=2 && turn_right(stk[stk.size()-2], stk.back(), nxt))
                stk.pop_back();
            stk.push_back(nxt);

            auto now = pair<int,int>{i, sum[i]};
            while (stk.size()>=2 && !turn_right(stk.front(), *(stk.begin()+1), now))
                stk.pop_front();
            
            ans = max(ans, (sum[i]-stk.front().second)*1.0 / (i-stk.front().first));
        }
        
        return ans;
    }
};