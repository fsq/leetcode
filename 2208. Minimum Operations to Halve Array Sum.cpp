class Solution {
public:
    int halveArray(vector<int>& a) {
        priority_queue<double> q(a.begin(), a.end());
        double s = accumulate(a.begin(), a.end(), 0ll), t = 0;
        int ans = 0;
        while (t*2 < s) {
            auto x = q.top();
            q.pop();
            t += x / 2;
            q.push(x / 2);
            ++ans;
        }
        return ans;
    }
};