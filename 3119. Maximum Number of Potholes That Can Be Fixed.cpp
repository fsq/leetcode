class Solution {
public:
    int maxPotholes(string s, int budget) {
        vector<int> a;
        for (int i=0,j; i<s.size(); i=j)
            if (s[i] == '.') {
                j = i + 1;
            } else {
                for (j=i; j<s.size() && s[j]=='x'; ++j);
                a.push_back(j - i);
            }
        sort(a.rbegin(), a.rend());
        int fix = 0;
        for (auto x : a) {
            int f = min(budget-1, x);
            fix += f;
            budget -= f + 1;
            if (budget <= 0) break;
        }
        return fix;
    }
};