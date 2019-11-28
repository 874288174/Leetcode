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
/*
class Vector2D {
public:
    Vector2D(vector<vector<int>>& v) {
        this->v = v;
    }
    
    int next() {
        hasNext();
        return v[i][j++];
    }
    
    bool hasNext() {
        if (i >= v.size()) return false;
        else if (j == v[i].size()) {
            i++;  
            j = 0;
            return hasNext();
        }
        return true;
    }
    
private:
    int i = 0, j = 0;
    vector<vector<int>> v;
};
 */