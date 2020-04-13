class Solution {
public:
    vector<string> stringMatching(vector<string>& a) {
        vector<string> ans;
        int n = a.size();
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                if (i!=j && a[j].find(a[i])!=string::npos) {
                    ans.push_back(a[i]);
                    break;
                }
        return ans;
    }
};