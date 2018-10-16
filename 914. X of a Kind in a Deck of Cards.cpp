class Solution {
public:
    
    int gcd(int a, int b) {
        return b==0 ? a : gcd(b, a%b);
    }
    
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> m;
        for (auto x : deck) ++m[x];
        
        int g = m.begin()->second;
        for (auto& kv : m)
            g = gcd(g, kv.second);
            
        return g>1;
    }
};