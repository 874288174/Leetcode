class Trie {
    friend class Solution;
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

    Trie* search(char c) {
        Trie *node = this; 
        if (!node->next.count(c)) return nullptr;
        else return node->next[c];
    }

private:
    unordered_map<char, Trie*> next;
    bool isword = false;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
       n = board.size(), m = board[0].size();
       visited.resize(n, vector<bool>(m, false));
       Trie *node = new Trie();
       for (auto i : words) node->insert(i);
       for (int i = 0; i < n; i++) {
           for (int j = 0; j < m; j++) {
               string s;
               dfs(i, j, s, node, board);
           }
       }
       vector<string> res;
       for (auto &i : My_set) res.push_back(i);
       return res;
    }
    
private:
    int n, m;
    unordered_set<string> My_set;
    vector<vector<bool>> visited;
    
    void dfs(int i, int j, string s, Trie *node, vector<vector<char>> &board) {
        if (i < 0 || i >= n || j < 0 || j >= m) return;
        else if (visited[i][j]) return;
        visited[i][j] = true;
        char c = board[i][j];
        s += c;
        if (!(node = node->search(c))) {
            visited[i][j] = false;
            return;
        } else if (node->isword) {
            My_set.insert(s);
        }
        dfs(i+1, j, s, node, board);
        dfs(i-1, j, s, node, board);
        dfs(i, j+1, s, node, board);
        dfs(i, j-1, s, node, board);
        visited[i][j] = false;
    }
}