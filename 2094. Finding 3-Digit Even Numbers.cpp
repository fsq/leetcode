class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int, int> c;
        vector<int> ans;
        for (auto d : digits) ++c[d];
        for (int i=100; i<=998; i+=2) {
            unordered_map<int, int> t;
            for (int p=i; p; p/=10) ++t[p%10];
            bool ok = true;
            for (auto& pr : t)
                if (pr.second > c[pr.first]) {
                    ok = false;
                    break;
                }
            if (ok) ans.push_back(i);
        }
        return ans;
    }
};