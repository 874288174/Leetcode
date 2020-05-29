class Solution {
public:
    string alienOrder(vector<string>& words) {
        g.resize(256);
        v.resize(256, 1);
        f(0, 0, words.size()-1, words);
        for (auto &s : words) for (auto &c : s)  v[c] = 0;
        string res;
        for (int i = 0; i < 256; i++) if (!v[i]) {
           if (!topo(i, res)) return "";
        }
        return res;
    }
    
private:
    vector<vector<int>> g;
    vector<int> v;
    
    void f(int pos, int st, int ed, vector<string> &words) {
        if (st >= ed || words[st].length() < pos) return;  
        char pre = words[st][pos];
        int new_st = st;
        for (int i = st; i <= ed; i++) {
            string &s = words[i];
            if (s[pos] != pre) {
                g[s[pos]].push_back(pre);
                pre = s[pos];
                f(pos+1, new_st, i-1, words);
                new_st = i;
            }
        }
        f(pos+1, new_st, ed, words);
    }
    
    
    bool topo(int i, string &res) {
        v[i] = -1;
        for (auto &j : g[i]) if (v[j] != 1) {
            if (v[j] == -1 || !topo(j, res)) return false;
        }
        v[i] = 1;
        res += char(i);
        return true;
    }
};