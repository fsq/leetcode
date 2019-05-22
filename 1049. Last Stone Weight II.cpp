class Solution {
public:
    
    int lastStoneWeightII(vector<int>& a) {
        int n = a.size(), s = accumulate(a.begin(), a.end(), 0);
        vector<int> f(s/2+1);
        f[0] = true;
        for (auto x : a)
            for (int i=s/2; i>=0; --i)
                if (f[i] && i+x<=s/2)
                    f[i+x] = true;
        
        for (int i=s/2; i>=0; --i)
            if (f[i])
                return s - 2*i;
        return 0;
    }
};