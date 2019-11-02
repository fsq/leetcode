class Solution {
public:
    vector<int> transformArray(vector<int>& a) {
        vector<int> b = a;
        while (true) {
            for (int i=1; i+1<b.size(); ++i) 
                if (a[i-1] > b[i] && b[i] < a[i+1]) 
                    ++b[i];
                else if (a[i-1] < b[i] && b[i] > a[i+1])
                    --b[i];
            if (b==a) return b;
            a = b;
        }
    }
};