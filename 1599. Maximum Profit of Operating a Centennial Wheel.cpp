class Solution {
public:
    int minOperationsMaxProfit(vector<int>& a, int x, int y) {
        int mx = INT_MIN, ans = 0;
        for (int use=0, i=0; i<a.size(); ++i) {
            int cur = min(4, a[i]);
            use += cur;   
            if (a[i] > 4)
                if (i+1==a.size())
                    a.push_back(a[i]-4);
                else
                    a[i+1] += a[i] - 4;
            
            int profit = use*x - y*(i+1);
            if (profit > mx) {
                ans = i + 1;
                mx = profit;
            }
        }
        return mx > 0 ? ans : -1;
    }
};