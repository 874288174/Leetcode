class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	int next();
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums), isPeek(false) {}

   
	int peek() {
        //return Iterator(*this).next();
        if (isPeek) return next_element;
        isPeek = true;
        return next_element = Iterator::next();
	}


	int next() {
        if (isPeek) {
            isPeek = false;
            return next_element;
        }
	    else return Iterator::next();
	}

	bool hasNext() const {
        if (isPeek) return true;
	    else return Iterator::hasNext();
	}
    
private:
    bool isPeek;
    int next_element;
};