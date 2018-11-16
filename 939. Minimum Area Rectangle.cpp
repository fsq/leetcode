class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, vector<int>> a;
        for (auto& p : points)
            a[p[0]].push_back(p[1]);
        for (auto& pr : a)
            sort(pr.second.begin(), pr.second.end());
        
        int ans = INT_MAX;
        for (auto i=a.begin(); i!=a.end(); ++i)
            for (auto j=next(i); j!=a.end(); ++j) 
                if (abs(i->first-j->first) < ans) {
                    auto& x = i->second;
                    auto& y = j->second;
                    bool first = true;
                    int pre = 0;
                    for (int p=0, q=0; p<x.size() && q<y.size();) {
                        while (p<x.size() && q<y.size() && x[p]!=y[q]) 
                            if (x[p]<y[q])
                                ++p;
                            else
                                ++q;
                        if (p<x.size() && q<y.size()) {
                            if (first) 
                                first = false;
                            else 
                                ans = min(ans, (x[p]-pre) * (abs(i->first-j->first))); 
                            pre = x[p];
                            ++p, ++q;
                        }
                    }
                }
        return ans==INT_MAX ? 0 : ans;
    }
};