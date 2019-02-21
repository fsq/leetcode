class Solution {
public:
    vector<int> addToArrayForm(vector<int>& a, int k) {
        reverse(a.begin(), a.end());

        for (int i=0; k; ++i, k/=10) {
            if (i==a.size())
                a.push_back(k%10);
            else 
                a[i] += k % 10;
            
            if (a[i]>9) {
                k += 10;
                a[i] -= 10;
            }
        }

        reverse(a.begin(), a.end());
        return a;
    }
};