class Solution {
public:
    vector<double> sampleStats(vector<int>& cnt) {
        vector<double> ans;
        double sum = 0, min = 256, max = -1;
        int n = 0, f = 0, mode = 0;
        for (int i=0; i<=255; ++i) 
            if (cnt[i]) {
                sum += i * cnt[i];
                n += cnt[i];
                if (min==256) min = i;
                max = i;
                if (cnt[i] > f) {
                    f = cnt[i];
                    mode = i;
                }
            }
        double med = 0;
        int x = 0, i = -1;
        do {
            x += cnt[++i];
        } while (x<n/2);
        if (x==n/2) {
            med = i;
            for (++i; !cnt[i]; ++i);
            med = (med + i) / 2.0;
        } else
            med = i;
        return {min, max, sum/n, med, mode};
    }
};