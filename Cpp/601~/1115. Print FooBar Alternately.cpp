class FooBar {
private:
    int n;
    mutex m1, m2;
public:
    FooBar(int n) {
        this->n = n;
        m2.lock();
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            m1.lock(); 
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            m2.unlock();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            m2.lock();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            m1.unlock();
        }
    }
};




////////////////////////////////////////////////////////
class FooBar {
private:
    int n;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lk(m);
            cv.wait(lk, [this](){return !state;});
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            state = true;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lk(m);
            cv.wait(lk, [this](){return state;});
    	    // printBar() outputs "bar". Do not change or remove this line.
    	    printBar();
            state = false;
            cv.notify_one();
        }
    }
    
    mutex m;
    condition_variable cv;
    bool state = false;
};