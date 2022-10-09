class ATM {
public:
    vector<int> dn = {20, 50, 100, 200, 500};
    vector<long long> a;
        
    ATM() {
        a.resize(5);
    }
    
    void deposit(vector<int> banknotesCount) {
        for (int i=0; i<5; ++i)
            a[i] += banknotesCount[i];
    }
    
    vector<int> withdraw(long long amount) {
        vector<int> w(5);
        for (int i=4; i>=0; --i)
            if (amount >= dn[i]) {
                w[i] = min(a[i], amount / dn[i]);
                amount -= w[i]*dn[i];
            }
        if (amount == 0) {
            for (int i=0; i<5; ++i)
                a[i] -= w[i];
            return w;
        } else {
            return {-1};
        }
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */