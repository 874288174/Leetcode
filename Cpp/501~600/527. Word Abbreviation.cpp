class Trie {
public:
    void insert(const string& s) {
        Trie* p = this;
        for (auto c : s) {
            if(!p->next.count(c))
                p->next[c] = new Trie();
            p = p->next[c];
            p->freq++;
        }
    }

    unordered_map<char, Trie*> next;
    int freq = 0;
};

class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        unordered_map<string, vector<int>> group;
        for(int i = 0; i < dict.size(); ++i) {
            string g = dict[i][0] + to_string(dict[i].size()) + dict[i].back();
            group[g].push_back(i);
        }
        vector<string> res(dict.size());

        for (auto& g : group) {
            Trie* trie = new Trie();
            for(auto& id : g.second) trie->insert(dict[id]);
            for(auto& id : g.second) {
                Trie* cur = trie;
                string temp, &s = dict[id];
                for(int i = 0; i < s.size(); ++i) {
                    char c = s[i];
                    if (cur->next[c]->freq == 1) {
                        int cnt = s.size()-i-2;
                        if (cnt >= 2)
                            temp = s.substr(0, i+1) + to_string(cnt) + s.back();
                        else
                            temp = s;
                        break;
                    }
                    cur = cur->next[c];
                }
                res[id] = temp;
            }   
        }
        return res;
    }
};