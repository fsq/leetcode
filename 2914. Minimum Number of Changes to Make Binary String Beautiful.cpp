class Solution {
public:
    int minChanges(string s) {
        vector<int> a;
        char pre = ' ';
        for (auto c : s)
            if (c == pre) {
                ++a.back();
            } else {
                a.push_back(1);
                pre = c;
            }
        int ans = 0;
        for (int i=0; i+1<a.size(); ++i)
            if (a[i] & 1) {
                ++ans;
                ++a[i+1];
            }
        return ans;
    }
};