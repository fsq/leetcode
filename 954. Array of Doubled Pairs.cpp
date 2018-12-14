class Solution {
public:
    bool canReorderDoubled(vector<int>& a) {
        vector<map<int,int>> mp(2);
        for (auto x : a)
           if (x>=0) ++mp[0][x];
                else ++mp[1][-x];
        
        if (mp[0][0] & 1) return false;
        for (auto& m : mp) 
            for (auto& kv : m)
                if (kv.second) {
                    if (!m.count(kv.first*2) || m[kv.first*2]<kv.second)
                        return false;
                    m[kv.first*2] -= kv.second;
                }
        
        return true;
    }
};