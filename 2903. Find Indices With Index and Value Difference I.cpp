class Solution {
public:
    vector<int> findIndices(vector<int>& a, int indexDifference, int valueDifference) {
        for (int i=0; i<a.size(); ++i)
            for (int j=i+indexDifference; j<a.size(); ++j)
                if (abs(a[i] - a[j]) >= valueDifference) {
                    return {i, j};
                }
        return {-1, -1};
    }
};