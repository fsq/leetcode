class Solution {
public:
    
    inline bool eq(double a, double b) {
        return fabs(a-b)<1e-6;
    }
    
    double dist(vector<int>& l) {
        return sqrt(pow(l[0], 2) + pow(l[1], 2));
    }
    
    double minAreaFreeRect(vector<vector<int>>& a) {
        int n = a.size();
        set<vector<int>> st(a.begin(), a.end());
        double ans = INT_MAX;
        
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                for (int k=0; k<n; ++k)
                    if (i!=j && i!=k && k!=j) {
                        vector<int> p4 = {a[j][0]+a[k][0]-a[i][0], a[j][1]+a[k][1]-a[i][1]};
                        if (st.count(p4)) {
                            vector<int> l1 = {a[k][0]-a[i][0], a[k][1]-a[i][1]};
                            vector<int> l2 = {a[j][0]-a[i][0], a[j][1]-a[i][1]};
                            if (eq(l1[0]*l2[0]+l1[1]*l2[1], 0) && !eq(l1[0]*l2[1], l1[1]*l2[0]))
                                ans = min(ans, dist(l1)*dist(l2));
                        }
                    }
        
        
        return ans==INT_MAX ? 0 : ans;
    }
};