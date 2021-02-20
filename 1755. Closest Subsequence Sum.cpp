class Solution {
public:
    
    vector<int> dfs(vector<int>& s, int l, int r) {
        unordered_set<int> st;
        for (int i=0; i<(1<<(r-l+1)); ++i) {
            int sum = 0;
            for (int j=0; j<r-l+1; ++j)
                if ((i>>j) & 1)
                    sum += s[l+j];
            st.insert(sum);
        }
        vector<int> a(st.begin(), st.end());
        sort(a.begin(), a.end());
        return a;
    }
    
    int minAbsDifference(vector<int>& s, int tar) {
        int ans = abs(tar);
        if (s.size()==1) {
            return min(ans, abs(s[0]-tar));
        }
        auto a = dfs(s, 0, s.size()/2-1);
        auto b = dfs(s, s.size()/2, s.size()-1);
        for (int i=0, j=b.size()-1; i<a.size() && ans!=0; ++i) {
            while (j>0 && a[i]+b[j]>tar) {
                ans = min(ans, a[i]+b[j]-tar);
                --j;
            }
            ans = min(ans, abs(a[i]+b[j]-tar));
        }
        return ans;
    }
};