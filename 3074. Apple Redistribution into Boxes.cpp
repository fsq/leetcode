class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& a) {
        int s = accumulate(apple.begin(), apple.end(), 0);
        sort(a.rbegin(), a.rend());
        for (int i=0; i<a.size(); ++i) {
            s -= a[i];
            if (s <= 0) {
                return i+1;
            }
        }
        return a.size();
    }
};