class Solution {
public:
    string originalDigits(string s) {
        string res;
        chars.resize(26, 0);
        for (auto &i : s) chars[i-'a']++;
        for (auto &pci : vect) {
            f(pci.first, pci.second, res);
        }
        sort(res.begin(), res.end());
        return res;
    }

private:
    vector<int> chars;
    vector<string> nums{"zero", "one", "two", "three", "four", 
                        "five", "six", "seven", "eight", "nine"};
    vector<pair<char, int>> vect{{'z', 0}, {'w', 2}, {'u', 4}, 
                                 {'x', 6}, {'r', 3}, {'f', 5},
                                 {'s', 7}, {'h', 8}, {'o', 1}, {'i', 9}};  
    void f(char c, int number, string &res) {
        int cnt = chars[c-'a'];
        for (auto &i : nums[number]) chars[i-'a'] -= cnt;
        res += string(cnt, '0'+number);
    }
};