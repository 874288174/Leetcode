class Trie {
public:
    void insert(const string &s) {
        Trie *p = this;
        for (auto c : s) {
            if (!p->mp.count(c)) {
                p->mp[c] = new Trie();
            }
            p = p->mp[c];
        }
        p->isWord = true;
    }

    bool isWord = false;
    unordered_map<char, Trie*> mp;
};

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        root = new Trie();
        for (const auto &s : words) root->insert(s);
        vector<string> res;
        for (const auto &s : words) {
            if (isConcatenatedWord(0, s.length(), s, root, 0)) {
                res.push_back(s);
            }
        }
        return res;
    }
private:
    Trie *root;

    bool isConcatenatedWord(int i, int n, const string &s, Trie *p, int cnt) {
        if (i >= n || !p->mp.count(s[i])) return false;
        p = p->mp[s[i]];
        if (p->isWord) {
            if (i == n-1) return cnt > 0;
            if (isConcatenatedWord(i+1, n, s, root, cnt+1)) return true;
        }
        return isConcatenatedWord(i+1, n, s, p, cnt);
    }
};