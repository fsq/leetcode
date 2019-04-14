class Solution {
public:
    bool divisorGame(int N) {
        // return N % 2 == 0;

        vector<int> f(N+1);
        f[1] = false;
        for (int i=2; i<=N; ++i) {
            bool win = false;
            for (int j=1; j<i; ++j)
                if (i % j==0 && !f[i-j]) {
                    win = true;
                    break;
                }
            f[i] = win;
        }
        return f[N];
    }
};