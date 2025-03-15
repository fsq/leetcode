class ZeroEvenOdd {
private:
    int n;
    binary_semaphore zero_sem{1}, odd_sem{0}, even_sem{0};
    int cur = 1;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while (true) {
            zero_sem.acquire();
            if (cur > n) break;
            printNumber(0);
            if (cur & 1) {
                odd_sem.release();
            } else {
                even_sem.release();
            }
        }
        odd_sem.release();
        even_sem.release();
    }

    void even(function<void(int)> printNumber) {
        while (true) {
            even_sem.acquire();
            if (cur > n) break;
            printNumber(cur);
            ++cur;
            zero_sem.release();
        }
    }

    void odd(function<void(int)> printNumber) {
        while (true) {
            odd_sem.acquire();
            if (cur > n) break;
            printNumber(cur);
            ++cur;
            zero_sem.release();
        }
    }
// Condition variable solution
/*
private:
    int n;
    int num = 1, turn = 0, target;

    mutex m;
    condition_variable cv;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        target = n + 1;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        unique_lock lk(m);
        while (true) {
            if (!lk.owns_lock()) lk.lock();
            cv.wait(lk, [this](){ return turn==0 || num==target; });
            if (num == target) return;
            turn = 1;
            printNumber(0);
            lk.unlock(); 
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        unique_lock lk(m);
        while (true) {
            if (!lk.owns_lock()) lk.lock();
            cv.wait(lk, [this](){ return (turn==1 && !(num & 1)) || num==target; });
            if (num == target) return;
            turn = 0;
            printNumber(num++);
            lk.unlock();
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        unique_lock lk(m);
        while (true) {
            if (!lk.owns_lock()) lk.lock();
            cv.wait(lk, [this](){ return (turn==1 && (num & 1)) || num==target; });
            if (num == target) return;
            turn = 0;
            printNumber(num++);
            lk.unlock();
            cv.notify_all();
        }
    }
*/
};