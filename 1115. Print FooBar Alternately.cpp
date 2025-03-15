class FooBar {
private:
    int n;
    binary_semaphore foo_sem{1}, bar_sem{0};

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            foo_sem.acquire();
            printFoo();
            bar_sem.release();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            bar_sem.acquire();
            printBar();
            foo_sem.release();
        }
    }


// Condition variable solution
/*
    int n;
    mutex m;
    condition_variable cv;
    int turn = 0;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        unique_lock lk(m);
        for (int i = 0; i < n; i++) {
            if (!lk.owns_lock()) lk.lock();
            cv.wait(lk, [this](){ return turn == 0; });
          printFoo();
            turn = 1;
            lk.unlock();
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        unique_lock lk(m);
        for (int i = 0; i < n; i++) {
            if (!lk.owns_lock()) lk.lock();
            cv.wait(lk, [this](){ return turn == 1; });
          printBar();
            turn = 0;
            lk.unlock();
            cv.notify_all();
        }
    }
*/
};