class ZeroEvenOdd {
private:
    int n, int_to_print = 1;
    mutex m;
    condition_variable cv;
    bool print_zero = true;
public:
    ZeroEvenOdd(int n) : n(n) {}

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while (int_to_print <= n) {
            unique_lock<mutex> lk(m);
            cv.wait(lk, [this] {return print_zero; });
            if (int_to_print <= n) printNumber(0);
            print_zero = false;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while (int_to_print <= n) {
            unique_lock<mutex> lk(m);
            cv.wait(lk, [this] {return !print_zero && int_to_print % 2 == 0; });
            if (int_to_print <= n) {
                printNumber(int_to_print++);
                print_zero = true;
            }
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        while (int_to_print <= n) {
            unique_lock<mutex> lk(m);
            cv.wait(lk, [this] {return !print_zero && int_to_print % 2 != 0; });
            if (int_to_print <= n) {
                printNumber(int_to_print++);
                print_zero = true;
            }
            cv.notify_all();
        }
    }
};
