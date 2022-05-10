class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0, i = 0;
        while (tickets[k]) {
            if (tickets[i] != 0) {
                ++ans;
                --tickets[i];
            }
            i = (i + 1) % tickets.size();
        }
        return ans;
    }
};