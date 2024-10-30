vector<long long> p;
class Solution {
public:
    vector<long long> buildP() {
        vector<long long> a;
        for (int i=1; i<=9; ++i) {
            a.push_back(i);
            a.push_back(i*10 + i);
            for (int j=0; j<=9; ++j) {
                a.push_back(i*100 + j*10 + i);
                a.push_back(i*1000 + j*100 + j*10 + i);
                for (int k=0; k<=9; ++k) {
                    a.push_back(i*10000 + j*1000 + k*100 + j*10 + i);
                    a.push_back(i*100000 + j*10000 + k*1000 + k*100 + j*10 + i);
                    for (int l=0; l<=9; ++l) {
                        a.push_back(i*1000000 + j*100000 + k*10000 + l*1000 + k*100 + j*10 + i);
                        a.push_back(i*10000000 + j*1000000 + k*100000 + l*10000 + l*1000 + k*100 + j*10 + i);
                        for (int m=0; m<=9; ++m) {
                            a.push_back(i*100000000 + j*10000000 + k*1000000 + l*100000 + m*10000 + l*1000 + k*100 + j*10 + i);
                        }
                    }
                }
            }
        }
        sort(a.begin(), a.end());
        return a;
    }

    long long minimumCost(vector<int>& a) {
        if (p.empty()) {
            p = buildP();
        }
        sort(a.begin(), a.end());
        vector<long long> s(a.size());
        s[0] = a[0];
        for (int i=1; i<a.size(); ++i) s[i] = s[i-1] + a[i];
        int i = 0;
        long long ans = LLONG_MAX;
        for (auto x : p) {
            while (i<a.size() && a[i]<x) ++i;
            long long cost = 0;
            if (i > 0) {
                cost += x*i - s[i-1];
            }
            if (i < a.size()) {
                cost += s.back()-(i==0 ? 0 : s[i-1]) - (s.size()-i)*x;
            }
            ans = min(ans, cost);
        }
        return ans;
    }
};