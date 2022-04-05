class CombinationIterator {
public:
    int len, mask;
    string s;
    CombinationIterator(string characters, int combinationLength) {
        s=characters;
        len = combinationLength;
        mask = (1 << characters.length()) - 1;
    }
    
    string next() {
        while(mask && __builtin_popcount(mask) != len) mask--;
        string out;
        for(int i=0; i< s.length(); i++) {
            if (mask & (1 << (s.length() - i - 1)))
                out += s[i];
        }
        mask--;
        return out;
    }
    
    bool hasNext() {
        while(mask && __builtin_popcount(mask) != len) mask--;
        if (!mask)
            return false;
        return true;
    }
};

