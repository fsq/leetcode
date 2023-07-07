class Solution {
public:

    int f(string& s) {
        int m = 0;
        for (auto x : s)
            m |= 1 << (x-'a');
        return m;
    }

    int similarPairs(vector<string>& w) {
        int ans = 0;
        for (int i=0; i<w.size(); ++i)
            for (int j=i+1; j<w.size(); ++j) {
                if (f(w[i])==f(w[j]))
                    ++ans;
            }
        return ans;
    }
};