class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& num, int limit) {
        vector<pair<int,int>> a;
        for (int i=0; i<num.size(); ++i) a.push_back({num[i], i});
        sort(a.begin(), a.end());
        for (int j,i=0; i<a.size(); i=j) {
            vector<int> id = {a[i].second};
            for (j=i+1; j<a.size() && a[j].first-a[j-1].first<=limit; ++j) {
                id.push_back(a[j].second);
            }
            sort(id.begin(), id.end());
            for (int k=0; k<id.size(); ++k) num[id[k]] = a[i+k].first;
        }
        return num;
    }
};