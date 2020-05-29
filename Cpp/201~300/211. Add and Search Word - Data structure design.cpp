class WordDictionary {
public:
  
    WordDictionary() {}
  
    void addWord(string word) {
        WordDictionary *node = this;
        for (char c : word) {
            if (!node->next.count(c)) {
                node->next[c] = new WordDictionary();
            }
            node = node->next[c];
        }
        node->isword = true;
    }

    bool search(string word) {
        return search(word, 0, word.length(), this);
    }

    bool search(const string &word, int cur, int n, WordDictionary *node) {
        for (int i = cur; i < n; i++) {
            char c = word[i];
            if (c == '.') {
                for (auto [cc, p] : node->next) {
                    if (search(word, i+1, n, p)) return true;
                }  
                return false;
            }
            else if (!node->next.count(c))  return false; 
            node = node->next[c];
        }
        return node->isword;
    }

private:
    unordered_map<char, WordDictionary*> next;
    bool isword = false;
};
