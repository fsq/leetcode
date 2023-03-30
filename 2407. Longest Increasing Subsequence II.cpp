class Solution {
public:
    int mx[500000], ans = 0;

    int getMax(int i, int l, int r, int a, int b) {
        if (a<=l && r<=b) return mx[i];
        int mid = (l+r) >> 1;
        if (a > mid)
            return getMax(i*2+1, mid+1, r, a, b);
        else if (b<=mid)
            return getMax(i*2, l, mid, a, b);
        else
            return max(getMax(i*2, l, mid, a, b), getMax(i*2+1, mid+1, r, a, b));
    }

    void update(int i, int l, int r, int pos, int val) {
        mx[i] = max(mx[i], val);
        if (l != r) {
            int mid = (l+r) >> 1;
            if (pos<=mid) 
                update(i*2, l, mid, pos, val);
            else
                update(i*2+1, mid+1, r, pos, val);
        }
    }

    int lengthOfLIS(vector<int>& a, int k) {
        memset(mx, 0, sizeof(mx));
        int n = *max_element(a.begin(), a.end());
        for (auto x : a) {
            int pre = 0;
            if (x > 1)
                pre = getMax(1, 1, n, max(1, x-k), x-1);
            update(1, 1, n, x, pre+1);
            ans = max(ans, pre+1);
        }
        return ans;
    }
};