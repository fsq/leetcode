class Foo {
public:

    binary_semaphore fst{1}, snd{0}, thr{0};
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        fst.acquire();
        printFirst();
        snd.release();
    }

    void second(function<void()> printSecond) {
        snd.acquire();
        printSecond();
        thr.release();
    }

    void third(function<void()> printThird) {
        thr.acquire();
        printThird();
    }

// Conditional varaible solution
/*
    mutex m;
    condition_variable cv; 
    int cur = 0;

    Foo() {
        
    }

    void first(function<void()> printFirst) {
        unique_lock lk(m);
        printFirst();
        cur = 1;
        lk.unlock();
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock lk(m);
        cv.wait(lk, [&](){ return cur==1; });
        cur = 2;
        printSecond();
        lk.unlock();
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock lk(m);
        cv.wait(lk, [&](){ return cur==2; });
        printThird();
        lk.unlock();
        cv.notify_all();
    }
*/
};