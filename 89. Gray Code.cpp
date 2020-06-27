class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> a = {0};
        for (int i=0; i<n; ++i)
            for (int j=a.size()-1; j>=0; --j)
                a.push_back((1<<i) | a[j]);
        return a;
    }
};