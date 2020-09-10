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









class CombinationIterator {
public:
    int len, mask;
    string s, characters;
    bool ok = true, end = false;
    
    CombinationIterator(string a, int n) {
        s = string(n, '1') + string(a.size() - n, '0');
        characters = a;
    }
    
    string next() {
        hasNext();
        ok = false;
        string res;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '1') 
                res += characters[i];
        }
        return res;
    }
    
    bool hasNext() {
       if (end) return false;
       if (ok) return true;
       if (!prev_permutation(s.begin(), s.end())) {
           end = true;
           return false;
       }
       return ok = true;
    }
};