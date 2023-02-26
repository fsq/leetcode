class Solution {
public:
    vector<long long> sum;
    vector<int> fa;

    int find(int x) {
        return fa[x]==x ? x : fa[x]=find(fa[x]);
    }

    void merge(int x, int y) {
        int fx=find(x), fy=find(y);
        if (fx != fy) {
            fa[fy] = fx;
            sum[fx] += sum[fy];
        }
    }

    vector<long long> maximumSegmentSum(vector<int>& a, vector<int>& qr) {
        int n = a.size();
        sum.resize(n);
        fa.resize(n);
        iota(fa.begin(), fa.end(), 0);
        vector<int> b(n);
        long long max_sum = 0;
        vector<long long> ans(n);
        for (int i=qr.size()-1; i>0; --i) {
            int p = qr[i];
            b[p] = sum[p] = a[p];
            if (p>0 && b[p-1]>0) merge(p-1, p);
            if (p+1<b.size() && b[p+1]>0) merge(p, p+1);
            max_sum = max(max_sum, sum[find(p)]);
            ans[i-1] = max_sum;
        }
        return ans;
    }
};