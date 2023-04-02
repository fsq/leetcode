class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& a) {
        vector<queue<int>> b(33);
        for (int j=0; j<a.size(); ++j) {
            int x = a[j];
            for (int i=0; i<32; ++i)
                if ((x>>i) & 1) {
                    b[i].push(j);
                }
        }
        vector<int> ans;
        for (int i=0; i<a.size(); ++i) {
            int m = 1;
            for (auto& q : b) {
                while (!q.empty() && q.front()<i) q.pop();
                if (!q.empty()) m = max(m, q.front()-i+1);
            }
            ans.push_back(m);
        }
        return ans;
    }
};