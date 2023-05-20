class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& a) {
        vector<int> q;
        vector<vector<int>> nxt(a.size());
        for (int i=0; i<a.size(); ++i) {
            int x = a[i];
            while (q.size() && x > a[q.back()]) {
                nxt[i].push_back(q.back());
                q.pop_back();
            }
            q.push_back(i);
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, std::greater<pair<int,int>>> pq;
        vector<int> ans(a.size(), -1);
        for (int i=0; i<a.size(); ++i) {
            auto x = a[i];
            while (!pq.empty() && pq.top().first<x) {
                ans[pq.top().second] = x;
                pq.pop();
            }
            for (auto ori : nxt[i]) pq.push({a[ori], ori});
        }
        return ans;
    }
};