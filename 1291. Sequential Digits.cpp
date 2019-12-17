class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int lo = to_string(low).size(), hi = to_string(high).size();
        vector<int> ans;
        for (int l=lo; l<=hi; ++l) {
            for (int a=1; a+l-1<=9; ++a) {
                int x = 0;
                for (int i=0; i<l; ++i) 
                    x = x*10 + a+i;
                if (x >= low && x <= high) ans.push_back(x);
            }
        }
        return ans;
    }
};