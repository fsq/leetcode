class Solution {
public:
    
    bool dfs(vector<int>& a, vector<int>& b, int i, int cap) {
        if (i==a.size()) return true;
        unordered_set<int> put;
        for (auto& x : b)
            if (x + a[i] <= cap && !put.count(x)) {
                put.insert(x);
                x += a[i];
                if (dfs(a, b, i+1, cap)) return true;
                x -= a[i];
            }
        return false;
    }
    
    int minimumTimeRequired(vector<int>& a, int k) {
        sort(a.begin(), a.end(), [](int x, int y) {
            return x > y;
        });
        int l = *max_element(a.begin(), a.end()), r = accumulate(a.begin(), a.end(), 0l);
        while (l < r) {
            int mid = (l + r) >> 1;
            vector<int> b(k);
            if (dfs(a, b, 0, mid)) 
                r = mid;
            else 
                l = mid + 1;
        }
        return l;
    }
};