class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& a) {
        int n = a.size();
        vector<double> ans(n, INT_MAX);
        ans.back() = -1;
        vector<int> q = {n-1};
        
        for (int i=n-2; i>=0; --i) {

            while (q.size() && a[i][1]<=a[q.back()][1]) 
                q.pop_back();

            while (q.size()>=2) {
                double t1 = 1.0 * (a[q[q.size()-1]][0] - a[i][0]) / (a[i][1] - a[q[q.size()-1]][1]);
                double t2 = 1.0 * (a[q[q.size()-2]][0] - a[i][0]) / (a[i][1] - a[q[q.size()-2]][1]);
                if (t1 >= t2) q.pop_back(); else break;
            }
            
            if (q.size())
                ans[i] = 1.0 * (a[q.back()][0] - a[i][0]) / (a[i][1] - a[q.back()][1]);
            else
                ans[i] = -1;

            q.push_back(i);
        }
        return ans;
    }
};