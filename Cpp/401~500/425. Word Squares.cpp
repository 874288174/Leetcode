class Solution {
public:
    class Trie{
    public:
        Trie() {}
        void insert(const string &s, int id) {
            Trie* p = this;
            for (auto c : s) {
                if (!p->mp.count(c)) p->mp[c] = new Trie();
                p = p->mp[c];
                p->index.push_back(id);
            }
            p->isWord = true;
        }

        Trie* search(const string &s) {
            Trie* p = this;
            for (auto c : s) {
                if (!p->mp.count(c)) return nullptr;
                p = p->mp[c];
            }
            return p;
        }
        
        vector<int> index;
    private:
        unordered_map<char, Trie*> mp;
        bool isWord = false;
    };

    vector<vector<string>> res;

    vector<vector<string>> wordSquares(vector<string>& words) {
        auto trie = new Trie();
        for (int i = 0; i < words.size(); ++i) trie->insert(words[i], i);

        vector<string> out(words[0].size());

        for (string word : words) {
            out[0] = word;
            helper(words, 1, trie, out);
        }
        return res;
    }

    void helper(const vector<string>& words, int level, Trie* trie, vector<string>& out) {
        if (level >= words[0].size()) {
            res.push_back(out);
            return;
        }
        string str = "";
        for (int i = 0; i < level; ++i) {
            str += out[i][level];
        }

        Trie *t = trie->search(str);
        if (t == nullptr) return;

        for (int idx : t->index) {
            out[level] = words[idx];
            helper(words, level + 1, trie, out);
        }
    }
};