class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
    }
    
    double next(int val) {
        q.push(val);
        if (q.size() > size) {
            sum -= q.front();
            q.pop();
        } 
        return (sum += val)/q.size();
    }
    
private:
    int size;
    double sum = 0;
    queue<int> q;
};
