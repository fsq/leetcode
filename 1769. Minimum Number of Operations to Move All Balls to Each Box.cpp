class Solution {
public:
    vector<int> minOperations(string a) {
        int l = 0, dl = 0, r=0, dr=0;
        for (int i=1; i<a.size(); ++i)
            if (a[i]=='1') {
                ++r;
                dr += i;
            }
        vector<int> ans;
        for (int i=0; i<a.size(); ++i) {
            ans.push_back(dl + dr);
            l += a[i]=='1';
            dl += l;
            dr -= r;
            r -= i+1<a.size() && a[i+1]=='1';
        }
        return ans;
    }
};