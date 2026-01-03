class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& a, vector<int>& b) {
        vector<int> gaps;
        int n = a.size();
        for (int i=0; i<n; ++i) {
            int prev = i==0 ? 0 : b[i-1];
            gaps.push_back(a[i] - prev);
        }
        gaps.push_back(eventTime - b.back());
        sort(gaps.begin(), gaps.end());
        int ans = 0;
        for (int i=0; i<n; ++i) {
            int window_start = i==0 ? 0 : b[i-1];
            int window_end = i+1==n ? eventTime : a[i+1];
            int gap1 = a[i] - window_start;
            int gap2 = window_end - b[i];
            bool use_gap1 = false, use_gap2 = false;
            int j = gaps.size() - 1;
            while (j >= 0) {
                if (gaps[j] == gap1 && !use_gap1) {
                    use_gap1 = true;
                    --j;
                } else if (gaps[j] == gap2 && !use_gap2) {
                    use_gap2 = true;
                    --j;
                } else {
                    break;
                }
            }
            if (j >= 0 && gaps[j] >= (b[i]-a[i])) {
                ans = max(ans, window_end - window_start);
            } else {
                ans = max(ans, window_end - window_start - (b[i]-a[i]));
            }
        }
        return ans;
    }
};
