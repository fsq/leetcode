class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long now = 0;
        unordered_map<int, long long> pre;
        for (auto x : tasks) {
            if (pre.count(x))
                now = max(now+1, pre[x]+space+1);
            else
                ++now;
            pre[x] = now;
        }
        return now;
    }
};