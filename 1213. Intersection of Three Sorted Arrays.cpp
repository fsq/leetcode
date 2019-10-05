class Solution {
public:
    vector<int> arraysIntersection(vector<int>& a, vector<int>& b, vector<int>& c) {
        vector<int> ans;
        int i=0, j=0, k=0;
        while (i<a.size() && j<b.size() && k<c.size()) 
            if (a[i]==b[j] && b[j]==c[k]) {
                ans.push_back(a[i]);
                ++i, ++j, ++k;
            } else if (a[i]<=b[j] && a[i]<=c[k])
                ++i;
            else if (b[j]<=a[i] && b[j]<=c[k])
                ++j;
            else 
                ++k;
        return ans;
    }
};