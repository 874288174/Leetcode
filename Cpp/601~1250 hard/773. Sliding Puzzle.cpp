class Solution {
public:
    const vector<vector<int>> dirs {
        {1,3}, {0,2,4}, {1,5},
        {0,4}, {1,3,5}, {2,4}
    };
    
    string vecToStr(vector<vector<int>> board) {
        string s;
        for (auto &v : board) {
            for (auto i : v) {
                s += char('0' + i);
            }
        }
        return s;
    }
    
    int slidingPuzzle(vector<vector<int>>& board) {
        auto start = vecToStr(board);
        auto goal = vecToStr({{1,2,3}, {4,5,0}});
        if (start == goal) return 0;
        
        set<string> st{start};
        queue<string> q;
        q.push(start);
        int cnt = 0;
        while (!q.empty()) {
            ++cnt;
            int sz = q.size();
            while (sz--) {
                auto u = q.front();
                q.pop();
                int pos = 0;
                while (u[pos] != '0') ++pos;
                
                for (auto newPos : dirs[pos]) {
                    auto t = u;
                    swap(t[newPos], t[pos]);
                    if (t == goal) return cnt;
                    if (st.count(t)) continue;
                    st.insert(t);
                    q.push(t);
                }
            }
            
        }
        return -1;
    }
};