class Solution {
public:
    vector<double> calcEquation(vector<vector<string>> &es, vector<double> &vs, vector<vector<string>> &qs) {
        for (int i = 0; i < es.size(); i++) {
            string a = es[i][0], b = es[i][1];
            if (!id.count(a)) id[a] = node(a);
            if (!id.count(b)) id[b] = node(b);
            Union(a, b, vs[i]);
        }
        vector<double> res;
        for (auto q : qs) {
            if (!id.count(q[0]) || !id.count(q[1]))
                res.push_back(-1);
            else {
                double va = 1, vb = 1;
                string fa_a = find(q[0], va);
                string fa_b = find(q[1], vb);
                if (fa_a != fa_b) res.push_back(-1);
                else res.push_back(va / vb);
            }
        }
        return res;
    }

private:
    struct node {
        node(string p = "", double v = 1.0) : parent(p), val(v){};
        string parent;
        double val;
    };

    unordered_map<string, node> id;
    
    string find(string s, double &v) {
        while (id[s].parent != s) {
            v = v * id[s].val;
            s = id[s].parent;
        }
        return s;
    }
    
    void Union(string a, string b, double v) {
        double va = 1.0, vb = 1.0;
        string fa_a = find(a, va);
        string fa_b = find(b, vb);
        id[fa_a] = node(fa_b, v*vb/va);
    }
};
