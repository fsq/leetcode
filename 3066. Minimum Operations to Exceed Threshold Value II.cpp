class Solution {
public:
    int minOperations(vector<int>& a, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> q(a.begin(), a.end());
        int ans = 0;
        while (q.top() < k) {
            long long x = q.top(); q.pop();
            long long y = q.top(); q.pop();
            q.push(2*min(x,y) + max(x,y));
            ++ans;
        }
        return ans;
    }
};