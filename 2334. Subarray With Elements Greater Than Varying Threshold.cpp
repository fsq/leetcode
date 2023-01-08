class Solution {
public:
    int validSubarraySize(vector<int>& a, int threshold) {
        vector<int> sl, sr, l(a.size()), r(a.size());
        for (int i=0; i<a.size(); ++i) {
            while (!sr.empty() && a[i]<a[sr.back()]) {
                r[sr.back()] = i;
                sr.pop_back();
            }
            sr.push_back(i);
        }
        while (!sr.empty()) {
            r[sr.back()] = a.size();
            sr.pop_back();
        }

        for (int i=a.size()-1; i>=0; --i) {
            while (!sl.empty() && a[i]<a[sl.back()]) {
                l[sl.back()] = i;
                sl.pop_back();
            }
            sl.push_back(i);
        }
        while (!sl.empty()) {
            l[sl.back()] = -1;
            sl.pop_back();
        }
        for (int i=0; i<a.size(); ++i) {
            if (a[i] > threshold/(r[i]-l[i]-1))
                return r[i]-l[i]-1;
        }
        return -1;
    }
};