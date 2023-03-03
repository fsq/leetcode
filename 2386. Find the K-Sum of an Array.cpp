class Solution {
public:
    long long kSum(vector<int>& a, int k) {
        priority_queue<pair<long long, int>> q;
        long long top = 0;
        for (auto& x : a)
            if (x > 0)
                top += x;
            else {
                x = -x;
            }
        if (k==1) return top;
        sort(a.begin(), a.end());
        q.push({top-a[0], 0});
        long long ans = 0;
        int rank = 0;
        while (q.size()) {
            auto [sum, i] = q.top(); 
            if (++rank == k-1) {
                ans = sum;
                break;
            }
            q.pop();
            if (i+1<a.size()) {
                q.push({sum-a[i+1], i+1});
                q.push({sum+a[i]-a[i+1], i+1});
            }
        }
        return ans;
    }
};