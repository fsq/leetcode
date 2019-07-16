class Solution {
public:
    int longestWPI(vector<int>& a) {
        a.insert(a.begin(), 0);
        for (int i=1; i<a.size(); ++i) 
            a[i] = a[i-1] + (a[i] > 8 ? 1 : -1);
        
        vector<int> s = {0};
        int p = 0, ans = 0;
        for (int i=1; i<a.size(); ++i) {
            if (a[s[p]] >= a[i]) {
                while (p+1<s.size() && a[s[p]] >= a[i]) ++p;
                if (a[s[p]] < a[i]) ans = max(ans, i - s[p]);
            } else {
                while (p>0 && a[s[p-1]]<a[i]) --p;
                ans = max(ans, i - s[p]);
            }
            if (a[i] < a[s.back()]) s.push_back(i);
        }
        return ans;
    }
};