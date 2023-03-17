class Solution {
public:
    int maximumRobots(vector<int>& charge, vector<int>& run, long long budget) {
        long long sum = 0;
        int ans = 0;
        deque<int> q;
        for (int l=0, r=0; r<charge.size(); ++r) {
            while (q.size() && charge[r]>=charge[q.back()]) q.pop_back();
            sum += run[r];
            q.push_back(r);
            while (q.size() && sum*(r-l+1)+charge[q.front()] > budget) {
                sum -= run[l];
                if (q.front()==l) q.pop_front();
                ++l;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};