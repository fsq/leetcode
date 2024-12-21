class Solution {
public:
    vector<int> resultArray(vector<int>& a) {
        vector<int> a1, a2;
        a1.push_back(a[0]);
        a2.push_back(a[1]);
        for (int i=2; i<a.size(); ++i)
            if (a1.back() > a2.back()) {
                a1.push_back(a[i]);
            } else {
                a2.push_back(a[i]);
            }
        for (auto x : a2)
            a1.push_back(x);
        return a1;
    }
};