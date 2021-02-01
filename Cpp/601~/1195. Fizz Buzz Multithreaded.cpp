class FizzBuzz {
    private:
        int n;
        atomic<int> current = 1;
        mutex mx;
        condition_variable cv;
    public:
        FizzBuzz(int n) {
            this->n = n;
        }
        // printFizz() outputs "fizz".
        void fizz(function<void()> printFizz) {
            do_work([&](int i){printFizz();}, [&]{return (current % 3 == 0 && current % 5 != 0);});
        }
        // printBuzz() outputs "buzz".
        void buzz(function<void()> printBuzz) {
            do_work([&](int i){printBuzz();}, [&]{return (current % 5 == 0 && current % 3 != 0);});
        }
        // printFizzBuzz() outputs "fizzbuzz".
        void fizzbuzz(function<void()> printFizzBuzz) {
            do_work([&](int i){printFizzBuzz();}, [&]{return (current % 5 == 0 && current % 3 == 0);});
        }
        // printNumber(x) outputs "x", where x is an integer.
        void number(function<void(int)> printNumber) {
            do_work(printNumber, [&]{return (current % 5 != 0 && current % 3 != 0);});
        }
    protected:
        void do_work(function<void(int)> printFunc, function<bool()> evalFunc) { 
            while (current <= n) {
                unique_lock<mutex> lk(mx);
                cv.wait(lk, [&]{return (evalFunc() || current > n);});
                if (current > n) break;
                printFunc(current++);
                cv.notify_all();
            }
        }
};