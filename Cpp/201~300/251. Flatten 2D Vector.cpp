class Vector2D {
public:
    Vector2D(vector<vector<int>> &v): x(v.begin()), end(v.end()) {}
    
    int next() {
        hasNext();
        return (*x)[y++];
    }
    
    bool hasNext() {
        while (x != end && y == (*x).size()) {
            ++x; 
            y = 0;
        }
        return x != end;
    }
private:
    int y = 0;
    vector<vector<int>>::iterator x, end;
};