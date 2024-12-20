class Solution {
public:

    bool isPrefixAndSuffix(string& a, string& b) {
        if (a.size()>b.size()) return false;
        return equal(a.begin(), a.end(), b.begin()) && equal(a.begin(), a.end(), b.end()-a.size());
    }

    int countPrefixSuffixPairs(vector<string>& s) {
        int ans = 0;
        for (int i=0; i<s.size(); ++i)
            for (int j=i+1; j<s.size(); ++j)
                if (isPrefixAndSuffix(s[i], s[j]))
                    ++ans;
        return ans;
    }
};