class Solution {
public:
    bool reorderedPowerOf2(int N) {
        vector<vector<int>> a;
        for (long long i=1; i<=(1ll<<33); i<<=1) {
            vector<int> s(10);
            for (auto t=i; t; t/=10)
                ++s[t%10];
            a.push_back(s);
        }
        vector<int> s(10);
        for (auto t=N; t; t/=10) ++s[t%10];
        return find(a.begin(), a.end(), s) != a.end();
    }
};