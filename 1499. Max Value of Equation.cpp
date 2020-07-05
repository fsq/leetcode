class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& a, int k) {
        deque<int> q;
        int ans = INT_MIN;
        for (int l=0, r=0; l<a.size(); ++l) {
            while (r<a.size() && a[r][0]<=a[l][0]+k) {
                while (q.size() && a[r][0]+a[r][1]>=a[q.back()][0]+a[q.back()][1]) {
                    q.pop_back();
                }
                q.push_back(r++);
            }
            if (q.front()==l) q.pop_front();
            if (q.size()) 
                ans = max(ans, a[q.front()][0]+a[q.front()][1]+a[l][1]-a[l][0]);
        }
        return ans;
    }
};