class Trie{
public:
    Trie(char c) : c(c), isword(false) {}
    Trie() {isword = false;}
    
    void insert(string &word) {
        Trie *node = this;
        for (char c : word) {
            if (node->isword) return;
            if (!node->next.count(c)) node->next[c] = new Trie();
            node = node->next[c];
        }
        node->isword = true;
    }
    
    
    string search(string &word) {
        Trie *node = this;
        string ret;
        for (char c : word) {
            if (node->isword) return ret;
            if (!node->next.count(c)) return word;            
            ret += c;
            node = node->next[c];
        }
        return ret;
    }
    
private:
    char c;
    bool isword;
    unordered_map<char, Trie*> next;
};


class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        string res, s;
        stringstream ss(sentence);
        Trie *root = new Trie();
        for (auto &s : dict) root->insert(s);
        bool isFirst = true;
        while (ss >> s) {
            if (isFirst) res += root->search(s);
            else res += " " + root->search(s);
            isFirst = false;
        } 
        return res;
    }
};