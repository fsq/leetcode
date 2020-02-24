class Cashier {
public:
    int cnt = 0, disc = 0, N = 0;
    unordered_map<int, int> p;
    
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        for (int i=0; i<prices.size(); ++i) p[products[i]] = prices[i];
        N = n;
        disc = discount;
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        ++cnt;
        double ans = 0;
        for (int i=0; i<product.size(); ++i)
            ans += amount[i] * p[product[i]];
        if (cnt == N) {
            cnt = 0;
            ans = (100-disc)/100.0 * ans;
        }
        return ans;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */