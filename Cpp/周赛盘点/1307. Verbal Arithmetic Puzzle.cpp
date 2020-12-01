class Solution {
public:
    int c2i[26], i2c[10];

    bool dfs(int index, int l, int sum, vector<string>& w, string &r) {
        if (l == r.length()) return sum == 0;
        
        if (index == w.size()) {
            if (c2i[r[l]-'A'] != -1) { 
                if (c2i[r[l]-'A'] != sum%10) return false;
                else return dfs(0, l+1, sum/10, w, r);
            }
            else if (i2c[sum%10] == -1) {
                if (l+1 == r.length() && sum%10 == 0)
                    return false;
                c2i[r[l]-'A'] = sum%10;
                i2c[sum%10] = r[l]-'A';
                if (dfs(0, l+1, sum/10, w, r)) return true; 
                c2i[r[l]-'A'] = i2c[sum%10] = -1;
                return false;
            }
            else return false;
        }
        if (l >= w[index].length()) return dfs(index+1, l, sum, w, r);

        if (c2i[w[index][l]-'A'] != -1)
            if (l+1 != w[index].length() || c2i[w[index][l]-'A'] != 0)
                return dfs(index+1, l, sum+c2i[w[index][l]-'A'], w, r);
        
        for(int i = 0; i < 10; i++) {
            if (i2c[i] != -1) continue;
            if (i == 0 && l+1 == w[index].length() && w[index].length() != 1) continue;
            i2c[i] = w[index][l]-'A';
            c2i[w[index][l]-'A'] = i;
            if (dfs(index+1, l, sum+i, w, r)) return true;
            i2c[i] = c2i[w[index][l]-'A'] = -1;
        }
        return false;
    }


    bool isSolvable(vector<string>& words, string result) {
        for(auto &w : words) {
            if (w.length() > result.length())
                return false;
        }

        memset(c2i, -1, sizeof(c2i));
        memset(i2c, -1, sizeof(i2c));
        for(auto &s : words) reverse(s.begin(), s.end());
        reverse(result.begin(), result.end());
        return dfs(0, 0, 0, words, result);
    }
};