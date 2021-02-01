class DiningPhilosophers {
public:
    pthread_mutex_t fork[5];
    
    DiningPhilosophers() {
        for (int i = 0; i < 5; ++i) {
            fork[i] = PTHREAD_MUTEX_INITIALIZER;
        }
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		if (philosopher & 1) {
            pthread_mutex_lock(&fork[(philosopher+1)%5]);
            pthread_mutex_lock(&fork[philosopher]);
        }
        else { 
            pthread_mutex_lock(&fork[philosopher]);
            pthread_mutex_lock(&fork[(philosopher+1)%5]);
        }
                    
        pickRightFork();
        pickLeftFork();

        eat();
         
        putLeftFork();
        putRightFork();
        
        pthread_mutex_unlock(&fork[philosopher]);
        pthread_mutex_unlock(&fork[(philosopher+1)%5]);
    }
};


