class Trie {
public:
    void insert(const string &s, int id) {
        auto p = this;
        for (auto c : s) {
            if (!p->mp.count(c)) {
                p->mp[c] = new Trie();
            }
            p->id = id;
            p = p->mp[c];
        }
        p->id = id;
    }
    
    int search(const string &s) {
        auto p = this;
        for (auto c : s) {
            if (!p->mp.count(c)) {
                return -1;
            }
            p = p->mp[c];
        }
        return p->id;
    }
    
    int id = -1;
    unordered_map<char, Trie*> mp;
};

class WordFilter {
public:
    Trie* trie = new Trie();
    
    WordFilter(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j <= words[i].size(); ++j) {
                string t = words[i].substr(j) + "#" + words[i];
                trie->insert(t, i);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        return trie->search(suffix + "#" + prefix);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */