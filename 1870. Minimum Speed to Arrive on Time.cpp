class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1, r = 100000000;
        while (l < r) {
            int m = (l+r) >> 1;
            double t = 0;
            for (int i=0; i+1<dist.size(); ++i)
                t += ceil(dist[i]*1.0 / m);
            t += dist.back() * 1.0 / m;
            if (t <= hour)
                r = m;
            else 
                l = m + 1;
        }
        return r==100000000 ? -1 : l;
    }
};