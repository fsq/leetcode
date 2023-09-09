class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans = accumulate(gifts.begin(), gifts.end(), 0ll);
        priority_queue<int> q(gifts.begin(), gifts.end());
        while (k--) {
            int x = q.top(); q.pop();
            int take = x - (int)sqrt(x);
            ans -= take;
            q.push(x-take);
        }
        return ans;
    }
};