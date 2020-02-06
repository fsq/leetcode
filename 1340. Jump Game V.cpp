class Solution {
public:
    int maxJumps(vector<int>& ar, int d) {
        vector<pair<int,int>> a;
        for (int i=0; i<ar.size(); ++i) a.push_back({ar[i], i});
        sort(a.begin(), a.end(), std::greater<pair<int,int>>());
        vector<int> f(a.size(), 1);
        
        for (int i=0; i<a.size(); ++i) {
            int x = a[i].second;
            for (int delta=-1; delta<=1; delta+=2)
                for (int j=x+delta; j<=x+d && j<a.size() && j>=x-d && j>=0; j+=delta) 
                    if (ar[j]>ar[x]) {
                        f[x] = max(f[x], f[j]+1);
                        break; // find the nearest one
                    }
        }
        return *max_element(f.begin(), f.end());
    }
};