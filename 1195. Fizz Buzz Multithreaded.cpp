class FizzBuzz {
private:
    int n, cur = 1;
    mutex m;
    condition_variable cv_fz, cv_bz, cv_fzbz, cv_num;

public:
    FizzBuzz(int n) {
        this->n = n;
        next();
    }

    bool loop(condition_variable& cv, function<bool()> cond, function<void(int)> print) {
        unique_lock lk(m);
        cv.wait(lk, cond);
        if (cur > n) return false;
        print(cur);
        ++cur;
        lk.unlock();
        next();
        return true;
    }

    void next() {
        if (cur > n) {
            cv_fz.notify_all();
            cv_bz.notify_all();
            cv_fzbz.notify_all();
            cv_num.notify_all();
        } else if (cur % 3 == 0 && cur % 5 == 0) {
            cv_fzbz.notify_one();
        } else if (cur % 3 == 0) {
            cv_fz.notify_one();
        } else if (cur % 5 == 0) {
            cv_bz.notify_one();
        } else {
            cv_num.notify_one();
        }
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (loop(cv_fz, [this](){ return cur>n || cur%3==0 && cur%5!=0; }, 
                    [&](int _) { printFizz(); }));
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (loop(cv_bz, [this](){ return cur>n || cur%3!=0 && cur%5==0; },
                    [&](int _) { printBuzz(); }));
    }

    // printFizzBuzz() outputs "fizzbuzz".
  void fizzbuzz(function<void()> printFizzBuzz) {
        while (loop(cv_fzbz, [this]() {return cur>n || cur%3==0 && cur%5==0; },
                    [&](int _) { printFizzBuzz(); }));
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (loop(cv_num, [this](){ return cur>n || cur%3!=0 && cur%5!=0; },
                    [&](int x) { printNumber(x); }));
    }
};