class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> a;
        for (int i=0; i<n; ++i) a.push_back({efficiency[i], speed[i]});
        sort(a.rbegin(), a.rend());
        
        priority_queue<int, vector<int>, greater<int>> q;
        long long sum = 0, ans = 0;
        for (int i=0; i<k; ++i) {
            q.push(a[i].second);
            sum += a[i].second;
            ans = max(ans, sum * a[i].first);
        }
        
        for (int i=k; i<n; ++i) {
            q.push(a[i].second);
            sum += a[i].second;
            sum -= q.top();
            q.pop();
            ans = max(ans, a[i].first * sum);
        }
        return ans % 1000000007;;
    }
};