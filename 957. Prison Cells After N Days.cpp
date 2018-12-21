class Solution {
public:
    
    int encode(const vector<int>& cells) {
        int x = 0;
        for (int i=0; i<8; ++i)
            x = (x<<1) | cells[i];
        return x;
    }
    
    vector<int> prisonAfterNDays(vector<int>& a, int N) {
        vector<int> cnt(1<<8, -1);
        
        cnt[encode(a)] = 0;
        vector<vector<int>> states;
        states.push_back(a);
        
        for (int i=1; i<=N; ++i) {
            vector<int> b(8);
            for (int i=1; i<7; ++i)
                b[i] = ! (a[i-1]^a[i+1]);
            int y = encode(b);
            if (cnt[y]!=-1) {
                int res = (N-cnt[y]) % (i-cnt[y]);
                return states[cnt[y]+res];
            } else 
                cnt[y] = i;
            a = move(b);
            states.push_back(a);
        }
        return a;
    }
};