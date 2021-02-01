class Trie {
public:
    void insert(const string &s) {
        auto p = this;
        for (int i = s.size()-1; i >= 0; --i) {
            if (!p->mp.count(s[i])) p->mp[s[i]] = new Trie();
            p = p->mp[s[i]];
        }
        p->isWord = true;
    }
    
    bool search(const string &s) {
        auto p = this;
        for (int i = s.size()-1; i >= 0; --i) {
            if (p->isWord) return true;
            if (!p->mp.count(s[i])) return false;
            p = p->mp[s[i]];
        }
        return p->isWord;
    }
    
    unordered_map<char, Trie*> mp;
    bool isWord = false;
};

class StreamChecker {
public:
    Trie* trie = new Trie();
    string s;
    
    StreamChecker(vector<string>& words) {
        for (auto &s : words)
            trie->insert(s);  
    }
    
    bool query(char letter) {
        s += letter;
        return trie->search(s);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */