class Solution {
public:
    struct node{
        int x, y, value;
        node(int x, int y, int value):x(x), y(y), value(value){}
        bool operator < (const node &rhs) const{
            return value > rhs.value;
        }
    };
    
    
   
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        const int dx[] = {1, 0};
        const int dy[] = {0, 1};
        int n = matrix.size();
        priority_queue<node> pq;
        pq.push({0, 0, matrix[0][0]});
        matrix[0][0] = INT_MIN;
        while(--k) {
            node t = pq.top();
            pq.pop();
            for (int i = 0; i < 2; i++) {
                int x = t.x+dx[i], y = t.y+dy[i];
                if (x < n && y < n && matrix[x][y] != INT_MIN) {
                    pq.push(node{x, y, matrix[x][y]});
                    matrix[x][y] = INT_MIN;
                }
            }
        }
        return pq.top().value;
    }
};