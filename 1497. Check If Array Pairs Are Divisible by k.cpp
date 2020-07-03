class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        for (auto x : arr) 
            ++m[(x % k + k) % k];

        for (auto& it : m) {
            int x = it.first;
            int &cnt = it.second;
            if (x==0 || !cnt) {
                continue;
            }
            
            if (m.count(k-x)) {
                if (x+x==k) {
                    if (cnt & 1) return false;
                    continue;
                }
                int &a = m[k-x];
                int ca = min(a, cnt);
                a -= ca, cnt -= ca;
            }
            
            if (cnt) return false;
        }
        return true;
    }
};