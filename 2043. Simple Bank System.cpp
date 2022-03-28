class Bank {
public:
    
    vector<long long> b;
    int n;
    
    Bank(vector<long long>& balance) {
        b = balance;
        n = b.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1<1 || account1>n || account2<1 || account2>n) return false;
        if (b[account1-1]<money) return false;
        b[account1-1] -= money;
        b[account2-1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (account<1 || account>n) return false;
        b[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (account<1 || account>n || b[account-1]<money) return false;
        b[account-1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */