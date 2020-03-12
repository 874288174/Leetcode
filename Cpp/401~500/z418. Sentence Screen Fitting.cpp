class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n = sentence.size();
        // 从第 i 个词开始 这一行能放下几遍句子
        vector<int> dp(n, 0);
        // 从第 i 个词开始 放下dp[i]遍句子后 变为第几个词
        vector<int> next(n, 0);
        for (int i = 0; i < n; ++i) {
            int cnt = 0, j = i, cur = cols;
            while (cur >= (int)sentence[j].size()) {
                cur -= sentence[j].size() + 1;
                if (++j == sentence.size()) {
                    ++cnt;
                    j = 0;
                }
            }
            dp[i] = cnt;
            next[i] = j;
        }	
        int res = 0, cur = 0;
	    for (int i = 0; i < rows; ++i) {
	        res += dp[cur];
            cur = next[cur];
        }
        return res;
    }
};