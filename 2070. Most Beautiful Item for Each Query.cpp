class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = queries.size();
        vector<int> qid(n);
        iota(qid.begin(), qid.end(), 0);
        sort(qid.begin(), qid.end(), [&](int a, int b) {
            return queries[a] < queries[b]; 
        });
        sort(items.begin(), items.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        int x = 0, i = 0;
        vector<int> ans(n);
        for (auto q : qid) {
            while (i<items.size() && items[i][0] <= queries[q]) {
                x = max(x, items[i][1]);
                ++i;
            }
            ans[q] = x;
        }
        return ans;
    }
};