class Solution {
public:
    vector<int> finalPrices(vector<int>& a) {
        stack<int> s;
        for (int i=0; i<a.size(); ++i) {
            while (!s.empty() && a[i]<=a[s.top()]) {
                a[s.top()] -= a[i];
                s.pop();
            }
            s.push(i);
        }
        return a;
    }
};