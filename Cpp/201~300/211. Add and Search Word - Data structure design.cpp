
class WordDictionary {
public:
  
    WordDictionary() {}
    
    /** Adds a word into the data structure. */
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
        WordDictionary *node = this;
        for (int i = 0; i < word.length(); i++) {
            char c = word[i];
            if (c == '.') {
                for (auto p : node->next) {
                    if (p.second->search(word.substr(i+1))) return true;
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