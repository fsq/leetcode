class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> ind;
    RangeFreqQuery(vector<int>& arr) {
        for (int i=0; i<arr.size(); ++i)
            ind[arr[i]].push_back(i);
    }
    
    int query(int left, int right, int value) {
        auto& a = ind[value];
        auto r = upper_bound(a.begin(), a.end(), right);
        auto l = lower_bound(a.begin(), a.end(), left);
        return r - l;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */