class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(), nums.end());
        long long ans = 0;
        while (k--) {
            long long x = q.top(); q.pop();
            ans += x;
            q.push((x+2)/3);
        }
        return ans;
    }
};