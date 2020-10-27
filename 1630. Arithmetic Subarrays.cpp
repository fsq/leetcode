class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& a, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for (int i=0; i<l.size(); ++i) {
            auto pr = minmax_element(a.begin()+l[i], a.begin()+r[i]+1);
            int mn = *pr.first, mx = *pr.second;
            if ((mx-mn) % (r[i]-l[i]) !=0) {
                ans.push_back(false);
                continue;
            }
            int gap = (mx - mn) / (r[i]-l[i]);
            if (gap==0) {
                ans.push_back(true);
                continue;
            }
            vector<int> fill(r[i]-l[i]+1);
            for (int j=l[i]; j<=r[i]; ++j) 
                if ((a[j]-mn) % gap==0 && (a[j]-mn)/gap<fill.size())
                    fill[(a[j]-mn) / gap] = true;
                else 
                    break;
            ans.push_back(accumulate(fill.begin(), fill.end(), 0) == fill.size());
        }
        return ans;
    }
};