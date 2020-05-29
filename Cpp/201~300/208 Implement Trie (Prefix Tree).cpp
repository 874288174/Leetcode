class Trie {
public:
    Trie() {}

    void insert(string word) {
        Trie *node = this;
        for (char c : word) {
            if (!node->next.count(c)) {node->next[c] = new Trie();}
            node = node->next[c];
        }
        node->isword = true;
    }

    bool search(string word) {
        Trie *node = this;
        for (char c : word) {
            if (!node->next.count(c))  return false; 
            node = node->next[c];
        }
        return node->isword;
    }

    bool startsWith(string prefix) {
        Trie *node = this;
        for (auto c : prefix) {
            if (!node->next.count(c))  return false; 
            node = node->next[c];
        }
        return true;
    }

private:
    unordered_map<char, Trie*> next;
    bool isword = false;
};



