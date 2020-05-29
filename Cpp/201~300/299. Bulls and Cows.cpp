class Solution {
public:
    string getHint(string secret, string guess) {
        int m[256] = {0};
        int bulls = 0, sum = 0, sz = guess.size();
        for (auto &c : secret) m[c]++;
        for (int i = 0; i < sz; ++i) {
            if (secret[i] == guess[i])   bulls++;
            if (m[guess[i]]) {
                sum++;
                m[guess[i]]--;
            }
        }
        return  to_string(bulls) + "A" + to_string(sum-bulls) + "B";
    }
};