class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        istringstream s(text);
        vector<string> ans, a;
        string x;
        while (s >> x) a.push_back(x);
        for (int i=2; i<a.size(); ++i)
            if (a[i-2]==first && a[i-1]==second)
                ans.push_back(a[i]);
        return ans;
    }
};