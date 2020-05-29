class Foo {   
    mutex m1, m2;
public:
    Foo() {
        m1.lock(), m2.lock();
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        m1.unlock();
    }

    void second(function<void()> printSecond) {
        m1.lock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        m2.unlock();
    }

    void third(function<void()> printThird) {
        m2.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};






//////////////////////////////////////////////////////////////////////////////////////
class Foo {
public:
    void first(function<void()> printFirst) {
        printFirst();
        ++p;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<std::mutex> guard(m);
        cv.wait(guard, [this] { return p == 1; });
        printSecond();
        ++p;
        cv.notify_one();
    }

    void third(function<void()> printThird) {
        unique_lock<std::mutex> guard(m);
        cv.wait(guard, [this]{ return p == 2; });
        printThird();
    }

private:
    condition_variable cv;
    mutex m;
    int p = 0;
};