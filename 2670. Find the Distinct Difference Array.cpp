class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& a) {
        unordered_map<int, int> cl, cr;
        int dl=0, dr=0;
        for (int i=0; i<a.size(); ++i) 
            if (++cr[a[i]] == 1)
                ++dr;
        vector<int> ans;
        for (int i=0; i<a.size(); ++i) {
            if (--cr[a[i]] == 0) --dr;
            if (++cl[a[i]] == 1) ++dl;
            ans.push_back(dl - dr);
        }
        return ans;
    }
};