class Solution {
public:
    
    const long double PI = 3.1415926;
    
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<long double> a;
        int free = 0;
        for (auto& p : points) 
            if (p==location) 
                ++free; 
            else {
                a.push_back(atan2(p[1]-location[1], p[0]-location[0]) * 180 / PI);
            }
        sort(a.begin(), a.end());        
        for (int t=a.size(), i=0; i<t; ++i)
            a.push_back(a[i] + 360);
        
        int ans = free;
        for (int l=0, r=0; l<points.size(); ++l) {
            while (r<a.size() && a[r]<=a[l]+angle) ++r;
            ans = max(ans, free+r-l);
        }
        
        return ans;
    }
};