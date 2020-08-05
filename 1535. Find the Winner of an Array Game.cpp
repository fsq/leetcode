class Solution {
public:
    int getWinner(vector<int>& a, int k) {
        int mx = *max_element(a.begin(), a.end());
        deque<int> q(a.begin(), a.end());
        int cons = 0, last = -1;
        while (true) {
            int x = q.front(); q.pop_front();
            int y = q.front(); q.pop_front();
            int winner;
            if (x > y) {
                q.push_front(x);
                q.push_back(y);
                winner = x;
            } else {
                q.push_front(y);
                q.push_back(x);
                winner = y;
            }
            if (winner == last) 
                ++cons;
            else {
                cons = 1;
                last = winner;
            }
            if (q.front() == mx || cons == k) return q.front();
        }
        return 0;
    }
};